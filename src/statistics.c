#define _CRT_SECURE_NO_WARNINGS
#include "price.h"
#include "./include/cJSON.h"
#include "card.h"
#include <stdbool.h>
#define SAME_MONTH_SAME_YEAR 3
#define DIFF_MONTH_SAME_YEAR 2
#define DIFF_MONTH_DIFF_YEAR 1

void statistics_print_out_an_user(char id[]) {
	int login_time = 0;
	int shut_time = 0;
	char readn[30];
	char s[150] = "";
	FILE *fp;
	if ((fp = fopen("./data/log.txt", "r")) == NULL) {
		printf("Can't Open File!");
		return;
	}
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	char *data = (char*)malloc(sizeof(char)*len + 1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);
	puts("卡号\t消费金额\t上机时间\t下机时间");
	while (ftell(fp) < len - 3) {
		fscanf(fp, "%s", readn);
		if (!strcmp(readn, id)) {
			fgets(s, 100, fp);
			printf("%s", readn); puts(s);
		}
	}
	fclose(fp);//关闭文件
}
void statistics_print_out_an_month(char id[]) {
}

float statistics_between(int time_left_year, int time_left_month,int time_left_day,int time_right_year,int time_right_month, int time_right_day){

	struct time {
		int year;
		int month;
		int day;
		int hour;
		int min;
		int sec;
		char wday[4];
	}readin_left,readin_right;
	float cost_money = 0.0;
	float sum = 0;
	char readin_id[MAX_ID];
	FILE *fp;
	if ((fp = fopen("./data/log.txt", "r")) == NULL) {
		printf("Can't Open File!");
		return;
	}
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	int flag = DIFF_MONTH_DIFF_YEAR;
	if (time_left_year == time_right_year) {
		flag = DIFF_MONTH_SAME_YEAR;
		if (time_left_month == time_right_month)
			flag = SAME_MONTH_SAME_YEAR;
	}
	while (ftell(fp) < len - 3) {
		if(!fscanf(fp, "%s\t%f\t%d年%d月%d日 %s  %d:%d:%d\t%d年%d月%d日 %s  %d:%d:%d", readin_id, &cost_money, &(readin_left.year), &(readin_left.month), &(readin_left.day), readin_left.wday, &(readin_left.hour), &(readin_left.min), &(readin_left.sec), &(readin_right.year), &(readin_right.month), &(readin_right.day), readin_right.wday, &(readin_right.hour), &(readin_right.min), &(readin_right.sec))) {
			return 0;
		}
		if (flag == SAME_MONTH_SAME_YEAR) {
			if (readin_right.day >= time_left_day && readin_right.day <= time_right_day)
				sum = sum + cost_money;
		}
		else if(flag == DIFF_MONTH_SAME_YEAR) {
			if(readin_right.month == time_left_month && readin_right.day >= time_left_day)        //与输入开始月同月时
				sum = sum + cost_money;
			else if (readin_right.month == time_right_month && readin_right.day <= time_right_day)        //与输入结束月同月时
				sum = sum + cost_money;
			else if (readin_right.month > time_left_month && readin_right.month < time_right_month)
				sum = sum + cost_money;
		}else if(flag == DIFF_MONTH_DIFF_YEAR){
			if(readin_right.year == time_left_year){
				if(readin_right.month > time_left_month)
						sum = sum + cost_money;
				else if(readin_right.month == time_left_month)
					if (readin_right.day >= time_left_day)
						sum = sum + cost_money;
			}
			else if (readin_right.year == time_right_year) {
				if (readin_right.month < time_right_month)
					sum = sum + cost_money;
				else if (readin_right.month == time_right_month)
					if (readin_right.day <= time_right_day)
						sum = sum + cost_money;
			}
			else if (readin_right.year > time_left_year && readin_right.year < time_right_year)
				sum = sum + cost_money;
		}
	}
	fclose(fp);
	return sum;
}

//int statistics_month_core(char [], int count, int cost) {
//	cJSON *root_json = NULL;
//	FILE *fp_1st = fopen(FILE_MONTH_LOG, "rb+");
//
//	if (fp_1st != NULL) {
//		fseek(fp_1st, 0, SEEK_END);
//		long len = ftell(fp_1st);
//		fseek(fp_1st, 0, SEEK_SET);
//		char *data = (char*)malloc(len + 1);
//		fread(data, 1, len, fp_1st);
//		fclose(fp_1st);
//		//		printf("%s", data);
//		root_json = cJSON_Parse(data);		//解析JSON数据
//	}else{
//		/*创建新对象*/
//		root_json = cJSON_CreateObject();		//root节点
//	}
//	cJSON *data_json = cJSON_CreateObject();		//管理员信息节点
//	cJSON_AddItemToObject(root_json, user, data_json);								//使data节点从属于root节点，并将data节点命名为用户名
//	cJSON_AddItemToObject(data_json, "username", cJSON_CreateString(user));			//用户名
//	cJSON_AddNumberToObject(data_json, "allow_cardman", allow_cardman);				//卡管理权限
//	cJSON_AddNumberToObject(data_json, "allow_billman", allow_billman);				//计费标准管理权限
//
//	char *buf = cJSON_Print(root_json);						//将json结构格式化到缓冲区
//
//	FILE *fp = fopen(FILE_MONTH_LOG, "wb+");
//	fwrite(buf, strlen(buf), 1, fp);
//
//	free(buf);
//	fclose(fp);
//
//	cJSON_Delete(root_json);
//	return 0;
//
//}