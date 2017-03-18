#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "card.h"
#include <string.h>
#include "price.h"


void writeLogLine(const char *content)
{
	FILE *fp;
	if ((fp = fopen("login.txt", "a")) == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp, "%s\n", content);
	fclose(fp);
}

void write_login(int time,const char *id){
	FILE *fp;
	if ((fp = fopen("login.txt", "a")) == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp, "%s%c%d%c", id,' ',time,'\n');
	fclose(fp);
}

int time_sec(void) {
	return (int)time((time_t*)NULL);
}

void login_in(void) {
	char id[MAX_ID];
	char passwd[MAX_PASSWD];
//	char str[25];
	printf("\n请输入卡号\n");
	scanf("%s", id);
	printf("\n请输入密码\n");
	scanf("%s", passwd);
	if(can_card_login(id, passwd)){
	write_login(time_sec(),id);
	printf("%d\n", time_sec());
	}else{
		printf("卡号或密码错误");
		getchar();
	}
}

void access_out(char id[]){
	FILE *fp;
	if ((fp = fopen("login.txt", "a+")) == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp,"%s%c%d",id,'\t',time_sec());
	fclose(fp);
}

int start_time_get(char id[]) {
	char temp[MAX_ID];
	temp[MAX_ID-1] = '\0';
	int time_left_interval;
	FILE *fp;
	if ((fp = fopen("login.txt", "r")) == NULL)
	{
		printf("Open Failed.\n");
		return 0;
	}
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%s%d", temp,&time_left_interval);
		if(strcmp(temp,id) == 0) {
			return time_left_interval;
		}
		if (feof(fp))
			break;
	}	
	fclose(fp);
	printf("\n未找到任何匹配数据\n");
	return 0;
}


void shut_log(void){
	FILE *fp;
	if ((fp = fopen("log.txt", "a+")) == NULL){
		printf("Open Failed.\n");
		return;
	}
	char *wday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	time_t now;
	struct tm *t;
	time(&now);
	t = localtime(&now);
	fprintf(fp,"%d年%d月%d日 ", (1900 + t->tm_year),(1 + t->tm_mon), t->tm_mday);
	fprintf(fp,"%s    %d:%d:%.2d\n", wday[t->tm_wday], t->tm_hour, t->tm_min, t->tm_sec);
	//fclose(fp);
}

void shut_core(char id[]) {
	int time,temp_int;
	char temp[MAX_ID];
	int time_left_interval = 0;
	int time_right_interval = time_sec();
	FILE *fp = NULL;
	temp[MAX_ID - 1] = '\0';
	if ((fp = fopen("rate.txt", "r+")) == NULL)
	{
		printf("File Open Failed.\n");
		return ;
	}
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%s%d", temp,&temp_int);
		if(!strcmp(id,temp)){
			fclose(fp);
			time_left_interval = temp_int;
			break;
		}
		if (feof(fp))
			break;
	}
	if(!time_left_interval)
		return;
	time = time_right_interval - time_left_interval;
	double price= price_read(time)*(time/3600.00);

}


/*
int main(void) {
	login_in();
	return 0;
}*/