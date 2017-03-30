#include "price.h"

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