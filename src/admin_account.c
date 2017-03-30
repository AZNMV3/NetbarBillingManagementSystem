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
			root_json = cJSON_Parse(data);		//解析JSON数据
		//}
	}else{
		/*创建新对象*/
		root_json = cJSON_CreateObject();		//root节点
	}

	cJSON *data_json = cJSON_CreateObject();		//管理员信息节点

	/*添加管理员信息（使用键值对）*/

//	cJSON_AddItemToObject(root_json, "name", cJSON_CreateString(user));		//root节点用户名 (废弃)
//	cJSON_AddItemToObject(root_json, user, cJSON_CreateString(user));		//root节点第一个用户名项 (废弃)

	cJSON_AddItemToObject(root_json, user, data_json);								//使data节点从属于root节点，并将data节点命名为用户名

	cJSON_AddItemToObject(data_json, "username", cJSON_CreateString(user));			//用户名
	cJSON_AddNumberToObject(data_json, "allow_cardman", allow_cardman);				//卡管理权限
	cJSON_AddNumberToObject(data_json, "allow_billman", allow_billman);				//计费标准管理权限
	cJSON_AddNumberToObject(data_json, "allow_shutman", allow_shutman);				//上下机管理权限
	cJSON_AddNumberToObject(data_json, "allow_chargeman", allow_chargeman);			//充值退费权限
	cJSON_AddNumberToObject(data_json, "allow_statman", allow_statman);				//查询统计权限
	cJSON_AddNumberToObject(data_json, "su", is_super);								//超级用户？
	cJSON_AddItemToObject(data_json, "userpass", cJSON_CreateString(password));		//密码

	char *buf = cJSON_Print(root_json);						//将json结构格式化到缓冲区

	FILE *fp = fopen(FILE_POSITION, "wb+");
	fwrite(buf, strlen(buf), 1, fp);

	/*	在文件结尾添加内容
	*	fseek(fp, 0, SEEK_CUR);
	*	fprintf(fp, "%c", ',');
	*/

	free(buf);
	fclose(fp);

	//释放json结构所占用的内存
	cJSON_Delete(root_json);
	return 0;

}

void admin_get_json_value(char name[], char password[], int *is_super, int *allow_cardman, int *allow_billman, int *allow_shutman, int *allow_chargeman, int *allow_statman) {

	//从文件中读取要解析的JSON数据
	FILE *fp = fopen(FILE_POSITION, "r");
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *data = (char*)malloc(len + 1);
	fread(data, 1, len, fp);
	fclose(fp);
	//	printf("%s", data);			//全盘输出json字符串

	//解析JSON数据
	cJSON *root_json = cJSON_Parse(data);    //将字符串解析成json结构体
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

	free(data);					//一定要！！！

}

void admin_get_information(void) {

	char user[MAX_USER_LEN];
	char passwd[MAX_PASSWD];

	int is_super = 0, allow_cardman = 0, allow_billman = 0, allow_shutman = 0, allow_chargeman = 0, allow_statman = 0;

	printf("请输入要查询的管理员的用户名(12个字符以内)\n");
	if (!scanf("%s", user)) {
		printf("\n输入非法！退出");
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
	
	free(data);					//一定要！！！

	if (!result)
		return 1;
	else
		return 0;

	return 0;
}

void admin_set_password(char name[],char newpasswd[]){
   /*
	* 修改某个子对象的stringvalue值，恐怕不能直接像修改整数的值这样
	* 字符串长度会有变化的，而该对象的内存已经事先分配好了
	* This is an object. We're in C. We don't have objects. But we do have structs.What's the framerate?
	* 对象的valuestring和string不能修改,只能直接获取,不需要删除
	* 只能再创建一次了，坑爹
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
	cJSON *root_json = cJSON_Parse(data);    //将字符串解析成json结构体
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

	cJSON *root_json = cJSON_Parse(data);    //将字符串解析成json结构体
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

	//从文件中读取要解析的JSON数据
	FILE *fp = fopen(FILE_POSITION, "r");
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