#include "admin.h"

extern unsigned char now_login_admin[MAX_USER_LEN];
int admin_add_core(char user[], char password[], int is_super, int allow_cardman, int allow_billman, int allow_shutman, int allow_chargeman, int allow_statman) {
	cJSON *root_json = NULL;
	FILE *fp_1st = fopen(FILE_POSITION, "rb+");

	if (fp_1st != NULL) {
		/*if (!feof(fp_1st)) {
		//	root_json = cJSON_CreateObject();
		}else{*/
			fseek(fp_1st, 0, SEEK_END);
			long len = ftell(fp_1st);
			fseek(fp_1st, 0, SEEK_SET);
			char *data = (char*)malloc(len + 1);
			fread(data, 1, len, fp_1st);
			fclose(fp_1st);
	//		printf("%s", data);
			root_json = cJSON_Parse(data);		//����JSON����
		//}
	}else{
		/*�����¶���*/
		root_json = cJSON_CreateObject();		//root�ڵ�
	}

	cJSON *data_json = cJSON_CreateObject();		//����Ա��Ϣ�ڵ�

	/*��ӹ���Ա��Ϣ��ʹ�ü�ֵ�ԣ�*/

//	cJSON_AddItemToObject(root_json, "name", cJSON_CreateString(user));		//root�ڵ��û��� (����)
//	cJSON_AddItemToObject(root_json, user, cJSON_CreateString(user));		//root�ڵ��һ���û����� (����)

	cJSON_AddItemToObject(root_json, user, data_json);								//ʹdata�ڵ������root�ڵ㣬����data�ڵ�����Ϊ�û���

	cJSON_AddItemToObject(data_json, "username", cJSON_CreateString(user));			//�û���
	cJSON_AddNumberToObject(data_json, "allow_cardman", allow_cardman);				//������Ȩ��
	cJSON_AddNumberToObject(data_json, "allow_billman", allow_billman);				//�Ʒѱ�׼����Ȩ��
	cJSON_AddNumberToObject(data_json, "allow_shutman", allow_shutman);				//���»�����Ȩ��
	cJSON_AddNumberToObject(data_json, "allow_chargeman", allow_chargeman);			//��ֵ�˷�Ȩ��
	cJSON_AddNumberToObject(data_json, "allow_statman", allow_statman);				//��ѯͳ��Ȩ��
	cJSON_AddNumberToObject(data_json, "su", is_super);								//�����û���
	cJSON_AddItemToObject(data_json, "userpass", cJSON_CreateString(password));		//����

	char *buf = cJSON_Print(root_json);						//��json�ṹ��ʽ����������

	FILE *fp = fopen(FILE_POSITION, "wb+");
	fwrite(buf, strlen(buf), 1, fp);

	/*	���ļ���β�������
	*	fseek(fp, 0, SEEK_CUR);
	*	fprintf(fp, "%c", ',');
	*/

	free(buf);
	fclose(fp);

	//�ͷ�json�ṹ��ռ�õ��ڴ�
	cJSON_Delete(root_json);
	return 0;

}

void admin_get_json_value(char name[], char password[], int *is_super, int *allow_cardman, int *allow_billman, int *allow_shutman, int *allow_chargeman, int *allow_statman) {

	//���ļ��ж�ȡҪ������JSON����
	FILE *fp = fopen(FILE_POSITION, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	//	printf("%s", data);			//ȫ�����json�ַ���

	//����JSON����
	cJSON *root_json = cJSON_Parse(data);    //���ַ���������json�ṹ��
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}


	cJSON *data_json = cJSON_GetObjectItem(root_json, name);

	/*	ONLY FOR EXAMPLE
	//username
	char *username = cJSON_Print(cJSON_GetObjectItem(data_json, "username"));
	printf("username:%s\n", username);
	free(username);
	//userpass
	char *userpass = cJSON_Print(cJSON_GetObjectItem(data_json, "userpass"));
	printf("userpass:%s\n", userpass);
	free(userpass);

	int is = cJSON_GetObjectItem(data_json, "su")->valueint;
	printf("%d", is);
	*/

	sprintf(password, "%s", cJSON_GetObjectItem(data_json, "userpass")->valuestring);

	*is_super = cJSON_GetObjectItem(data_json, "su")->valueint;
	*allow_cardman = cJSON_GetObjectItem(data_json, "allow_cardman")->valueint;
	*allow_billman = cJSON_GetObjectItem(data_json, "allow_billman")->valueint;
	*allow_shutman = cJSON_GetObjectItem(data_json, "allow_shutman")->valueint;
	*allow_chargeman = cJSON_GetObjectItem(data_json, "allow_chargeman")->valueint;
	*allow_statman = cJSON_GetObjectItem(data_json, "allow_statman")->valueint;

	free(data);					//һ��Ҫ������

}

void admin_get_information(void) {

	char user[MAX_USER_LEN];
	char passwd[MAX_PASSWD];

	int is_super = 0, allow_cardman = 0, allow_billman = 0, allow_shutman = 0, allow_chargeman = 0, allow_statman = 0;

	printf("������Ҫ��ѯ�Ĺ���Ա���û���(12���ַ�����)\n");
	if (!scanf("%s", user)) {
		printf("\n����Ƿ����˳�");
		return;
	}

	admin_get_json_value(user, passwd, &is_super, &allow_cardman, &allow_billman, &allow_shutman, &allow_chargeman, &allow_statman);
	printf("\n%s", passwd);
	printf("\n%d", is_super);

	system("pause");
}

int admin_get_permission(char * user, char type) {
	char passwd[MAX_PASSWD];
	int is_super = 0, allow_cardman = 0, allow_billman = 0, allow_shutman = 0, allow_chargeman = 0, allow_statman = 0;
	admin_get_json_value(user, passwd, &is_super, &allow_cardman, &allow_billman, &allow_shutman, &allow_chargeman, &allow_statman);
	free(passwd);
	switch (type){
		case 'a':if (allow_cardman == 1) {
			return 1;
		};
			break;
		case 'b':if (allow_billman == 1) {
			return 1;
		};
			break;
		case 'm':if (allow_shutman == 1) {
			return 1;
		};
			break;
		case 'c':if (allow_chargeman == 1) {
			return 1;
		};
			break;
		case 's':if (allow_statman == 1) {
			return 1;
		};
			break;
		default:if (is_super == 1) {
			return 1;
		};
			break;
	}
	return 0;
}

int admin_is_passwd_right(char name[],char password[]) {

	FILE *fp = fopen(FILE_POSITION, "r");
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

	cJSON *data_json = cJSON_GetObjectItem(root_json, name);
	int result = strcoll(password, cJSON_GetObjectItem(data_json, "userpass")->valuestring);
	
	free(data);					//һ��Ҫ������

	if (!result)
		return 1;
	else
		return 0;

	return 0;
}

void admin_set_password(char name[],char newpasswd[]){
   /*
	* �޸�ĳ���Ӷ����stringvalueֵ�����²���ֱ�����޸�������ֵ����
	* �ַ������Ȼ��б仯�ģ����ö�����ڴ��Ѿ����ȷ������
	* This is an object. We're in C. We don't have objects. But we do have structs.What's the framerate?
	* �����valuestring��string�����޸�,ֻ��ֱ�ӻ�ȡ,����Ҫɾ��
	* ֻ���ٴ���һ���ˣ��ӵ�
	*/
	FILE *fp = fopen(FILE_POSITION, "r");
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
	cJSON *data_json = cJSON_GetObjectItem(root_json, name);
	cJSON_DeleteItemFromObject(data_json,"userpass");
	cJSON_AddItemToObject(data_json, "userpass", cJSON_CreateString(newpasswd));

	char *buf = cJSON_Print(root_json);
	FILE *fp2 = fopen(FILE_POSITION, "wb+");
	fwrite(buf, strlen(buf), 1, fp2);
	free(buf);
	fclose(fp2);
	cJSON_Delete(root_json);
}


void admin_del_core (char name[]) {
	FILE *fp = fopen(FILE_POSITION, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	cJSON *root_json = cJSON_Parse(data);    //���ַ���������json�ṹ��
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}

	cJSON_DeleteItemFromObject(root_json, name);

	char *buf = cJSON_Print(root_json);
	FILE *fp2 = fopen(FILE_POSITION, "wb+");
	fwrite(buf, strlen(buf), 1, fp2);
	free(buf);
	fclose(fp2);
	cJSON_Delete(root_json);
}

int admin_has_user(char name[]){
	FILE *fp = fopen(FILE_POSITION, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);

	cJSON *root_json = cJSON_Parse(data);    //���ַ���������json�ṹ��
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return 0;
	}
	if (cJSON_HasObjectItem(root_json, name))
		return 1;

	return 0;
}

void admin_set_permission(char *name, char type, int new_value) {

	//���ļ��ж�ȡҪ������JSON����
	FILE *fp = fopen(FILE_POSITION, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);

	cJSON *root_json = cJSON_Parse(data);    //���ַ���������json�ṹ��
	if (NULL == root_json)
	{
		printf("error:%s\n", cJSON_GetErrorPtr());
		cJSON_Delete(root_json);
		return;
	}

	cJSON *data_json = cJSON_GetObjectItem(root_json, name);
	switch (type) {
	case 'a':cJSON_GetObjectItem(data_json, "allow_cardman")->valueint = new_value;
		break;
	case 'b':cJSON_GetObjectItem(data_json, "allow_billman")->valueint = new_value;
		break;
	case 'm':cJSON_GetObjectItem(data_json, "allow_shutman")->valueint = new_value;
		break;
	case 'c':cJSON_GetObjectItem(data_json, "allow_chargeman")->valueint = new_value;
		break;
	case 's':cJSON_GetObjectItem(data_json, "allow_statman")->valueint = new_value;
		break;
	case '1': {

		cJSON_GetObjectItem(data_json, "su")->valueint = new_value;
		cJSON_GetObjectItem(data_json, "allow_cardman")->valueint = new_value;
		cJSON_GetObjectItem(data_json, "allow_billman")->valueint = new_value;
		cJSON_GetObjectItem(data_json, "allow_shutman")->valueint = new_value;
		cJSON_GetObjectItem(data_json, "allow_chargeman")->valueint = new_value;
		cJSON_GetObjectItem(data_json, "allow_statman")->valueint = new_value;
	}
			  break;
	default:return;
	}

	char *buf = cJSON_Print(root_json);
	fp = fopen(FILE_POSITION, "wb+");
	fwrite(buf, strlen(buf), 1, fp);
	free(buf);
	free(data);
	fclose(fp);
	cJSON_Delete(root_json);
}

struct admin write_permissions(char user[]) {
	struct admin result;
	char passwd[MAX_PASSWD];
	admin_get_json_value(user, result.password, &(result.is_super), &(result.allow_cardman), &(result.allow_billman), &(result.allow_shutman), &(result.allow_chargeman), &(result.allow_statman));
	return result;
}