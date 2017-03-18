#include"price.h"

#define DEFAULT_PRICE 2.5


void price_add(void) {
	int time_left_interval, time_right_interval;
	float hour, price;
	printf("\n������۸���������\n");
	printf("\n������۸�ʼ����(��λ:Сʱ������������С�������λ��\n");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	printf("\n������۸��������(��λ:Сʱ������������С�������λ��\n");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	printf("\n������۸�(��λ:Ԫ,�����������֣�\n");
	scanf("%f", &price);
	price_add_core(time_left_interval, time_right_interval, price);

}

void price_del_core(int time_left_interval) {
	FILE *fp;

	char s[150]="";			//���ڱ���
	int n=0;				//�������������� 

	if ((fp = fopen("rate.txt", "r")) == NULL) {
		printf("Can't Open File!");
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	char *data = (char*)malloc(sizeof(char)*len+1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);

	/* atoi (ascii to integer) �ǰ��ַ���ת������������һ������*/
	
	while (ftell(fp) < len-3) {
		fgets(s, 100, fp);
		n = atoi(s);					//�Ӷ�ȡ����Ϣȡ������������
		if (n == time_left_interval){
			strcat(data, "\n");
			continue;
		}
		strcat(data, s);				//�����ȡ������Ϣ */
	}
	fclose(fp);
	fp = fopen("rate.txt", "wb+");		//������д�ķ�ʽ���ļ� 
	fputs(data, fp);					//���ڴ���Ϣ�洢���ļ��� 
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
		printf("\n������Ҫ�޸ĵļ۸�ʼ����(��λ:Сʱ������������С�������λ��\n");
		scanf("%f", &hour);
		time_left_interval = (int)(1.0 * hour * 3600);
		printf("\n�������µļ۸��������(��λ:Сʱ������������С�������λ��\n");
		scanf("%f", &hour);
		time_right_interval = (int)(1.0 * hour * 3600);
		printf("\n�������¼۸�(��λ:Ԫ,�����������֣�\n");
		scanf("%f", &price);
		price_del_core(time_left_interval);
		price_add_core(time_left_interval, time_right_interval, price);
	}

