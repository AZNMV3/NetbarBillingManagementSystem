#include "login.h"
#include "card.h"
#include "price.h"


void writeLogLine(const char *content)
{
	FILE *fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "a")) == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp, "%s\n", content);
	fclose(fp);
}

void write_login(int time, const char *id){
	FILE *fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "a")) == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp, "%s%c%d%c", id, ' ', time, '\n');
	fclose(fp);
}

int time_sec(void){
	return (int)time((time_t*)NULL);
}


void access_out(char id[]){
	FILE *fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "a+")) == NULL){
		printf("Open Failed.\n");
		return;
	}
	fprintf(fp, "%s%c%d", id, '\t', time_sec());
	fclose(fp);
}

int start_time_get(char id[]){
	char temp[MAX_ID];
	temp[MAX_ID - 1] = '\0';
	int time_left_interval;
	FILE *fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "r")) == NULL){
		printf("Open Failed.\n");
		return 0;
	}
	while (1){
		if (feof(fp))
			break;
		fscanf(fp, "%s%d", temp, &time_left_interval);
		if (strcmp(temp, id) == 0){
			return time_left_interval;
		}
		if (feof(fp))
			break;
	}
	fclose(fp);
	printf("\n未找到任何匹配数据\n");
	return 0;
}


void shut_log(char id[], int ago, float cost_money){
	FILE *fp;
	if ((fp = fopen("./data/log.txt", "a+")) == NULL){
		printf("Open Failed.\n");
		return;
	}
	char *wday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	long long a = ago;
	time_t now;
	struct tm *start, *stop;
	time(&now);
	start = localtime(&a);
	stop = localtime(&now);
	fprintf(fp, "%s\t", id);
	fprintf(fp, "%.2f\t", cost_money);
	fprintf(fp, "%d年%d月%d日 ", (1900 + start->tm_year), (1 + start->tm_mon), start->tm_mday);
	fprintf(fp, "%s  %d:%d:%.2d\t", wday[start->tm_wday], start->tm_hour, start->tm_min, start->tm_sec);
	fprintf(fp, "%d年%d月%d日 ", (1900 + stop->tm_year), (1 + stop->tm_mon), stop->tm_mday);
	fprintf(fp, "%s  %d:%d:%.2d\n", wday[stop->tm_wday], stop->tm_hour, stop->tm_min, stop->tm_sec);
	fclose(fp);
}

void shut_core(char id[]){
	int time, temp_int;
	char temp[MAX_ID];
	int time_left_interval = 0;
	int time_right_interval = time_sec();
	FILE *fp = NULL;
	temp[MAX_ID - 1] = '\0';
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "r+")) == NULL)
	{
		printf("File Open Failed.\n");
		return;
	}
	while (1){
		if (feof(fp))
			break;
		fscanf(fp, "%s%d", temp, &temp_int);
		if (!strcmp(id, temp)){
			fclose(fp);
			time_left_interval = temp_int;
			break;
		}
		if (feof(fp))
			break;
	}
	printf("\n%d", time_left_interval);
	if (!time_left_interval)
		return;
	time = time_right_interval - time_left_interval;
	double cost_money = price_read(time)*(time / 3600.00);
	cost(id, cost_money);
	del_after(id);
	shut_log(id, time_left_interval, cost_money);
}

void del_after(char id[]){
	FILE *fp;
	char s[160] = "";			//用于保存
	char temp[MAX_ID];
	temp[MAX_ID - 1] = '\0';

	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "r")) == NULL){
		printf("Can't Open File!");
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	if(len == 0){
		puts("不存在");
		return;
	}
	char *data = (char*)malloc(sizeof(char)*len + 1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);
	int temp_int;
	while (ftell(fp) < len - 3){
		fgets(s, 150, fp);
		sscanf(s, "%s%d", temp, &temp_int);
		if (!strcmp(temp, id)){
			strcat(data, "\n");
			continue;
		}
		strcat(data, s);			//保存读取到的信息 */
	}
	fclose(fp);
	fp = fopen(CARD_LOGIN_FILE_POSITION, "wb+");		//重新以写的方式打开文件 
	fputs(data, fp);					//把内存信息存储到文件中 
	fclose(fp);
	fflush(stdin);
}
