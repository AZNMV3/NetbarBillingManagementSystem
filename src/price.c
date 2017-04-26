#include"price.h"
#include <direct.h>
#include <io.h>


void price_del_core(int time_left_interval){
	FILE *fp;

	char s[150] = "";			//���ڱ���
	int n;				//�������������� 

	if ((fp = fopen(RATE_FILE_POSITION, "r")) == NULL){
		printf("Can't Open File!");
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	char *data = (char*)malloc(sizeof(char)*len + 1);
	*data = 0;
	fseek(fp, 0, SEEK_SET);

	/* atoi (ascii to integer) �ǰ��ַ���ת������������һ������*/

	while (ftell(fp) < len - 3){
		fgets(s, 100, fp);
		n = atoi(s);					//�Ӷ�ȡ����Ϣȡ������������
		if (n == time_left_interval){
			strcat(data, "\n");
			continue;
		}
		strcat(data, s);				//�����ȡ������Ϣ */
	}
	fclose(fp);
	fp = fopen(RATE_FILE_POSITION, "wb+");		//������д�ķ�ʽ���ļ� 
	fputs(data, fp);					//���ڴ���Ϣ�洢���ļ��� 
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
		fscanf(fp, "%d%d%f", &time_left_interval, &time_right_interval, &price);
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

bool is_price_file_exist(void) {
	signed int result = _access(RATE_FILE_POSITION, 0);
	if (result == 0)
		return true;
	return false;
}