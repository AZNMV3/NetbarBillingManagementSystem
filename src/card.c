#include "card.h"


int card_add_core(char id[], char passwd[],float balance) {
	cJSON *root_json = NULL;
	FILE *fp_1st = fopen(FILE_NAME, "rb+");

	if (fp_1st != NULL) {
		/*if(!feof(fp_1st)){
			root_json = cJSON_CreateObject();
		  }else{*/
		fseek(fp_1st, 0, SEEK_END);
		long len = ftell(fp_1st);
		fseek(fp_1st, 0, SEEK_SET);
		char *data = (char*)malloc(len + 1);
		fread(data, 1, len, fp_1st);
		fclose(fp_1st);
	//	printf("%s", data);
		root_json = cJSON_Parse(data);	//解析JSON数据
	//	}
	}else{
		/*创建新对象*/
		root_json = cJSON_CreateObject();		//root节点
	}

	cJSON *data_json = cJSON_CreateObject();		//卡信息节点

	cJSON_AddItemToObject(root_json, id, data_json);						//使data节点从属于root节点，并将data节点命名为卡号

	cJSON_AddItemToObject(data_json, "id", cJSON_CreateString(id));			//卡号
	cJSON_AddNumberToObject(data_json, "balance", balance);				//余额
	cJSON_AddItemToObject(data_json, "userpass", cJSON_CreateString(passwd));		//密码

	char *buf = cJSON_Print(root_json);						//将json结构格式化到缓冲区

	FILE *fp = fopen(FILE_NAME, "wb+");
	fwrite(buf, strlen(buf), 1, fp);

	free(buf);
	fclose(fp);

	//释放json结构所占用的内存
	cJSON_Delete(root_json);
	return 0;

}

float card_get_json_value(char id[], char password[]) {
	float balance = 0;
	//从文件中读取要解析的JSON数据
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);

	cJSON *root_json = cJSON_Parse(data);    //将字符串解析成json结构体
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return 0;
	}


	cJSON *data_json = cJSON_GetObjectItem(root_json, id);

	sprintf(password, "%s", cJSON_GetObjectItem(data_json, "userpass")->valuestring);

	balance =(float) cJSON_GetObjectItem(data_json, "balance")->valuedouble;

	free(data);					//一定要！！！
	return balance;
}


int card_is_passwd_right(char id[],char passwd[]) {

	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);

	cJSON *root_json = cJSON_Parse(data);   
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return 0;
	}

	cJSON *data_json = cJSON_GetObjectItem(root_json, id);
	int result = strcoll(passwd, cJSON_GetObjectItem(data_json, "userpass")->valuestring);
	
	free(data);					//一定要！！！

	if (!result)
		return 1;
	else
		return 0;
	return 0;
}

void card_set_password(char id[],char newpasswd[]){
  /**
	* This is an object. We're in C. We don't have objects. But we do have structs.What's the framerate?
	*/
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	cJSON *root_json = cJSON_Parse(data);
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}
	cJSON *data_json = cJSON_GetObjectItem(root_json, id);
	cJSON_DeleteItemFromObject(data_json,"userpass");
	cJSON_AddItemToObject(data_json, "userpass", cJSON_CreateString(newpasswd));

	char *buf = cJSON_Print(root_json);
	FILE *fp2 = fopen(FILE_NAME, "wb+");
	fwrite(buf, strlen(buf), 1, fp2);
	free(buf);
	fclose(fp2);
	cJSON_Delete(root_json);
}


void card_del_core (char id[]) {
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	cJSON *root_json = cJSON_Parse(data);    //将字符串解析成json结构体
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}

	cJSON_DeleteItemFromObject(root_json, id);

	char *buf = cJSON_Print(root_json);
	FILE *fp2 = fopen(FILE_NAME, "wb+");
	fwrite(buf, strlen(buf), 1, fp2);
	free(buf);
	fclose(fp2);
	cJSON_Delete(root_json);
}

int card_has(char id[]){
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);

	cJSON *root_json = cJSON_Parse(data);    //将字符串解析成json结构体
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return 0;
	}
	if (cJSON_HasObjectItem(root_json, id))
		return 1;

	return 0;
}

void top_up (char id[],float money){
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	cJSON *root_json = cJSON_Parse(data);
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}
	cJSON *data_json = cJSON_GetObjectItem(root_json, id);
	float balance = (float)cJSON_GetObjectItem(data_json, "balance")->valuedouble;
	balance += money;
	cJSON_GetObjectItem(data_json, "balance")->valuedouble = balance;

	char *buf = cJSON_Print(root_json);
	FILE *fp2 = fopen(FILE_NAME, "wb+");
	fwrite(buf, strlen(buf), 1, fp2);
	free(buf);
	fclose(fp2);
	cJSON_Delete(root_json);
}

void cost(char id[], float money) {
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	cJSON *root_json = cJSON_Parse(data);
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}
	cJSON *data_json = cJSON_GetObjectItem(root_json, id);
	float balance = (float)cJSON_GetObjectItem(data_json, "balance")->valuedouble;
	balance -= money;
	cJSON_GetObjectItem(data_json, "balance")->valuedouble = balance;
	char *buf = cJSON_Print(root_json);
	FILE *fp2 = fopen(FILE_NAME, "wb+");
	fwrite(buf, strlen(buf), 1, fp2);
	free(buf);
	fclose(fp2);
	cJSON_Delete(root_json);
}

int	can_card_login(char id[], char passwd[]) {
	FILE *fp = fopen(FILE_NAME, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);

	cJSON *root_json = cJSON_Parse(data);
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return 0;
	}

	cJSON *data_json = cJSON_GetObjectItem(root_json, id);
	int result = strcoll(passwd, cJSON_GetObjectItem(data_json, "userpass")->valuestring);
	float balance = (float)cJSON_GetObjectItem(data_json, "balance")->valuedouble;
	free(data);					//一定要！！！

	if (!result)
		if (balance >= 0.40)
			return 1;
		else
			return 0;

	return 0;
}
