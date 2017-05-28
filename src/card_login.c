#include "login.h"
#include "card.h"
#include "price.h"


void writeLogLine(const char* content)
{
	FILE* fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "a")) == NULL) {
		printf("Open Failed.\n");
		printf("error value: %d, %s\n", errno, strerror(errno));
		return;
	}
	fprintf(fp, "%s\n", content);
	fclose(fp);
}

void write_login(int time, const char* id)
{
	FILE* fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "a")) == NULL) {
		printf("Open Failed.\n");
		printf("error value: %d, %s\n", errno, strerror(errno));
		return;
	}
	fprintf(fp, "%s%c%d%c", id, ' ', time, '\n');
	fclose(fp);
}

int time_sec(void)
{
	return (int)time((time_t*)NULL);
}


//void access_out(char id[]) 
//{
//	FILE *fp;
//	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "a+")) == NULL) {
//		printf("Open Failed.\n");
//		return;
//	}
//	fprintf(fp, "%s%c%d", id, '\t', time_sec());
//	fclose(fp);
//}

int start_time_get(char id[])
{
	char temp[MAX_ID];
	temp[MAX_ID - 1] = '\0';
	int time_left_interval;
	FILE* fp;
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "r")) == NULL) {
		printf("Open Failed.\n");
		return 0;
	}
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%s%d", temp, &time_left_interval);
		if (strcmp(temp, id) == 0) {
			return time_left_interval;
		}
		if (feof(fp))
			break;
	}
	fclose(fp);
	printf("\n未找到任何匹配数据\n");
	return 0;
}


void shut_log(char id[], int ago, double cost_money)
{
	FILE* fp = NULL;
	char str[100];
	if ((fp = fopen(CARD_LOG, "a+")) == NULL) {
		printf("Open Failed.\n");
		printf("error value: %d, %s\n", errno, strerror(errno));
		return;
	}
	time_t a = ago;
	time_t now;
	struct tm *start, *stop;
	time(&now);
	start = localtime(&a);
	/*
	 * 严重警告:不允许连续调用localtime函数
	 * 一旦调用了localtime函数，应该马上取出tm结构体中的内容
	 * 否则会覆盖之前的数据
	 */
	strftime(str, sizeof(str), "%Y年%m月%d日%a  %X", start);
	fprintf(fp, "%s\t", id);
	fprintf(fp, "%.2f\t", cost_money);
	fprintf(fp, "%s\t", str);
	stop = localtime(&now);
	strftime(str, sizeof(str), "%Y年%m月%d日%a  %X", stop);
	fprintf(fp, "%s\n", str);
	fclose(fp);
}

void shut_core(char id[])
{
	int time, temp_int;
	char temp[MAX_ID];
	int time_left_interval = 0;
	int time_right_interval = time_sec();
	FILE* fp = NULL;
	temp[MAX_ID - 1] = '\0';
	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "r+")) == NULL) {
		printf("File Open Failed.\n");
		printf("error value: %d, %s\n", errno, strerror(errno));
		return;
	}
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%s%d", temp, &temp_int);
		if (!strcmp(id, temp)) {
			fclose(fp);
			time_left_interval = temp_int;
			break;
		}
		if (feof(fp))
			break;
	}
	if (!time_left_interval)
		return;
	time = time_right_interval - time_left_interval;
	double cost_money = price_read(time) * (time / 3600.00);
	cost(id, cost_money);
	del_after(id);
	shut_log(id, time_left_interval, (float)cost_money);
}

void del_after(char id[])
{
	FILE* fp;
	char s[160] = ""; //用于保存
	char temp[MAX_ID];
	temp[MAX_ID - 1] = '\0';

	if ((fp = fopen(CARD_LOGIN_FILE_POSITION, "r")) == NULL) {
		puts("Can't Open File!");
		printf("error value: %d, %s\n", errno, strerror(errno));
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	if (len == 0) {
		puts("不存在");
		return;
	}
	char* data = (char*)malloc(sizeof(char) * len + 1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);
	int temp_int;
	while (ftell(fp) < len - 3) {
		fgets(s, 150, fp);
		sscanf(s, "%s%d", temp, &temp_int);
		if (!strcmp(temp, id)) {
			strcat(data, "\n");
			continue;
		}
		strcat(data, s); //保存读取到的信息 */
	}
	fclose(fp);
	fp = fopen(CARD_LOGIN_FILE_POSITION, "wb+"); //重新以写的方式打开文件 
	fputs(data, fp); //把内存信息存储到文件中 
	fclose(fp);
	fflush(stdin);
}
