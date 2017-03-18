#include"price.h"

#define DEFAULT_PRICE 2.5


void price_add(void) {
	int time_left_interval, time_right_interval;
	float hour, price;
	printf("\n请输入价格适用区间\n");
	printf("\n请输入价格开始区间(单位:小时，可以输入至小数点后两位）\n");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	printf("\n请输入价格结束区间(单位:小时，可以输入至小数点后两位）\n");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	printf("\n请输入价格(单位:元,可以输入至分）\n");
	scanf("%f", &price);
	price_add_core(time_left_interval, time_right_interval, price);

}

void price_del_core(int time_left_interval) {
	FILE *fp;

	char s[150]="";			//用于保存
	int n=0;				//保存左区间秒数 

	if ((fp = fopen("rate.txt", "r")) == NULL) {
		printf("Can't Open File!");
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	char *data = (char*)malloc(sizeof(char)*len+1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);

	/* atoi (ascii to integer) 是把字符串转换成整型数的一个函数*/
	
	while (ftell(fp) < len-3) {
		fgets(s, 100, fp);
		n = atoi(s);					//从读取的信息取得左区间秒数
		if (n == time_left_interval){
			strcat(data, "\n");
			continue;
		}
		strcat(data, s);				//保存读取到的信息 */
	}
	fclose(fp);
	fp = fopen("rate.txt", "wb+");		//重新以写的方式打开文件 
	fputs(data, fp);					//把内存信息存储到文件中 
	fclose(fp); 
}

void price_add_core(int time_left_interval, int time_right_interval, float price){
	FILE *fp = NULL;
	if ((fp = fopen("rate.txt", "a+")) == NULL) {
		printf("Can't Open File!");
		return;
	}
	fprintf(fp, "%d%c%d%c%.2f%c", time_left_interval, ' ',time_right_interval,' ',price,'\n');

	fclose(fp);
}

float price_read(int time_sec){
	float price = 2.5;
	int time_left_interval , time_right_interval;
	FILE *fp = NULL;
	if ((fp = fopen("rate.txt", "r")) == NULL)
	{
		printf("File Open Failed.\n");
		return DEFAULT_PRICE;
	}
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%f%d%d", &price,&time_left_interval, &time_right_interval);
		if(time_sec > time_left_interval && time_sec <= time_right_interval){
			fclose(fp);
			return price;
		}
		if (feof(fp))
			break;
	}
	
	fclose(fp);
	return DEFAULT_PRICE;
}

void price_set(void){
		int time_left_interval, time_right_interval;
		float hour, price;
		printf("\n请输入要修改的价格开始区间(单位:小时，可以输入至小数点后两位）\n");
		scanf("%f", &hour);
		time_left_interval = (int)(1.0 * hour * 3600);
		printf("\n请输入新的价格结束区间(单位:小时，可以输入至小数点后两位）\n");
		scanf("%f", &hour);
		time_right_interval = (int)(1.0 * hour * 3600);
		printf("\n请输入新价格(单位:元,可以输入至分）\n");
		scanf("%f", &price);
		price_del_core(time_left_interval);
		price_add_core(time_left_interval, time_right_interval, price);
	}

