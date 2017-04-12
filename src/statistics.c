#include "price.h"
#include "./include/cJSON.h"
#include "card.h"
#include <stdbool.h>
#include <time.h>
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
void statistics_print_out_an_month(void) {
	time_t get_now_time;
	time(&get_now_time);
	struct tm *now= localtime(&get_now_time);
	int now_year = now->tm_year + 1900;
	int now_month = now->tm_mon;
	int mon = now_year * 12 + now->tm_mon;
	int i = 11,k = mon,year = now_year,month =  now_month;
	char string_year[10] , string_year_prev[10];
	sprintf(string_year, "%d年", now_year);
	sprintf(string_year_prev, "%d年", now_year-1);
	struct stat {
		int year;
		int month;
		float cost;
		int count;
	}a[12];
	for(mon -= 12;k > mon;k--,i--,month--) {
		a[i].cost = statistics_between(year, month, 1, year, month, 31, &(a[i].count));
		a[i].year = year;
		a[i].month = month;
		if (month <= 1){
			year--;
			month = 13;
		}
	}
	FILE *fp;
	if ((fp = fopen(MONTH_STAT_FILE_POSITION, "w+")) == NULL) {
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp, "各月统计\n");
	for (i = 0; i < 12; i++) {
		fprintf(fp, "\t%d年%d月\n", a[i].year, a[i].month);
		fprintf(fp, "\t\t上机次数:%d\n\t\t营业额:%.2f元\n\n", a[i].count, a[i].cost);
	}
	fclose(fp);
}

float statistics_between(int time_left_year, int time_left_month, int time_left_day, int time_right_year, int time_right_month, int time_right_day, int *count) {
	*count = 0;
	struct time {
		int year;
		int month;
		int day;
		int hour;
		int min;
		int sec;
		char wday[4];
	}readin_left, readin_right;
	float cost_money = 0.0;
	float sum = 0;
	char readin_id[MAX_ID];
	FILE *fp;
	if ((fp = fopen("./data/log.txt", "r")) == NULL) {
		printf("Can't Open File!");
		return 0;
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
		if (!fscanf(fp, "%s\t%f\t%d年%d月%d日 %s  %d:%d:%d\t%d年%d月%d日 %s  %d:%d:%d", readin_id, &cost_money, &(readin_left.year), &(readin_left.month), &(readin_left.day), readin_left.wday, &(readin_left.hour), &(readin_left.min), &(readin_left.sec), &(readin_right.year), &(readin_right.month), &(readin_right.day), readin_right.wday, &(readin_right.hour), &(readin_right.min), &(readin_right.sec))) {
			return 0;
		}
		if (flag == SAME_MONTH_SAME_YEAR) {
			if (readin_right.year >= time_left_year && readin_right.year <= time_right_year)
				if (readin_right.month >= time_left_month && readin_right.month <= time_right_month)
					if (readin_right.day >= time_left_day && readin_right.day <= time_right_day){
						sum = sum + cost_money;
						(*count)++;
					}
		}
		else if (flag == DIFF_MONTH_SAME_YEAR) {
			if (readin_right.month == time_left_month && readin_right.day >= time_left_day) {        //与输入开始月同月时
				sum = sum + cost_money;
				*count += 1;
			}
			else if (readin_right.month == time_right_month && readin_right.day <= time_right_day) {        //与输入结束月同月时
				sum = sum + cost_money;
				*count += 1;
			}
			else if (readin_right.month > time_left_month && readin_right.month < time_right_month){
				sum = sum + cost_money;
				*count += 1;
			}
		}
		else if (flag == DIFF_MONTH_DIFF_YEAR) {
			if (readin_right.year == time_left_year) {
				if (readin_right.month > time_left_month){
					sum = sum + cost_money;
					*count += 1;
				}
				else if (readin_right.month == time_left_month)
					if (readin_right.day >= time_left_day){
						sum = sum + cost_money; 
						*count += 1;
					}
			}
			else if (readin_right.year == time_right_year) {
				if (readin_right.month < time_right_month){
					sum = sum + cost_money;
					*count += 1;
				}
				else if (readin_right.month == time_right_month)
					if (readin_right.day <= time_right_day){
						sum = sum + cost_money;
						*count += 1;
					}
			}
			else if (readin_right.year > time_left_year && readin_right.year < time_right_year){
				sum = sum + cost_money;
				(*count)++;
			}
		}
	}
	fclose(fp);
	return sum;
}

bool statistics_month_core(void){

	return true;
}