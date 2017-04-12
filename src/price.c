#include"price.h"


void price_del_core(int time_left_interval){
	FILE *fp;

	char s[150] = "";			//用于保存
	int n;				//保存左区间秒数 

	if ((fp = fopen(RATE_FILE_POSITION, "r")) == NULL){
		printf("Can't Open File!");
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	char *data = (char*)malloc(sizeof(char)*len + 1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);

	/* atoi (ascii to integer) 是把字符串转换成整型数的一个函数*/

	while (ftell(fp) < len - 3){
		fgets(s, 100, fp);
		n = atoi(s);					//从读取的信息取得左区间秒数
		if (n == time_left_interval){
			strcat(data, "\n");
			continue;
		}
		strcat(data, s);				//保存读取到的信息 */
	}
	fclose(fp);
	fp = fopen(RATE_FILE_POSITION, "wb+");		//重新以写的方式打开文件 
	fputs(data, fp);					//把内存信息存储到文件中 
	fclose(fp);
}

void price_add_core(int time_left_interval, int time_right_interval, float price){
	FILE *fp = NULL;
	if ((fp = fopen(RATE_FILE_POSITION, "a+")) == NULL){
		printf("Can't Open File!");
		return;
	}
	fprintf(fp, "%d%c%d%c%.2f%c", time_left_interval, ' ', time_right_interval, ' ', price, '\n');

	fclose(fp);
}

float price_read(int time_sec){
	float price = 2.5;
	int time_left_interval, time_right_interval;
	FILE *fp = NULL;
	if ((fp = fopen(RATE_FILE_POSITION, "r")) == NULL){
		printf("File Open Failed.\n");
		return DEFAULT_PRICE;
	}
	while (1){
		if (feof(fp))
			break;
		fscanf(fp, "%f%d%d", &price, &time_left_interval, &time_right_interval);
		if (time_sec > time_left_interval && time_sec <= time_right_interval){
			fclose(fp);
			return price;
		}
		if (feof(fp))
			break;
	}

	fclose(fp);
	return DEFAULT_PRICE;
}