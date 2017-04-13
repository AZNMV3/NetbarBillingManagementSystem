#include "../menu.h"
#include "../admin.h"


void purview_man_menu(void){
	while (true){
		system("cls");
		system("color 2f");
		purview_man_head();
		line_breaks(1);
		purview_man_option();
		line_breaks(2);
		prompt_input();
		menu_purview_man_jump();
	}
}

void purview_man_head(void){
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	purview_man_content();
	line_breaks(1);
	print_equals(80);
}

void purview_man_content(void){
	puts_center("欢迎使用本网吧计费管理系统————权限管理");
	line_breaks(1);
	puts_center("在权限管理您可以添加、删除管理员或者配置他们的权限。");
	puts_center("注意:只有超级管理员有权进行设置。");
	line_breaks(1);
}

void purview_man_option(void){
	printf("\t【1.添加管理员】\t【2.删除管理员】\t【3.配置权限】\t【0.返回】");
}

void purview_man_add_admin(void){
	system("cls");
	print_equals(80);
	line_breaks(1);
	char user[MAX_USER_LEN];
	char passwd[MAX_PASSWD];
	char temp = 0;
	printf("\n=======添加管理员======\n");
	printf("请输入要添加的管理员的用户名(12个字符以内)\n");
	if (!scanf("%s", user)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	printf("\n请输入要添加的管理员的密码\n");
	if (!scanf("%s", passwd)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}

	int is_super = 0, allow_cardman = 0, allow_billman = 0, allow_shutman = 0, allow_chargeman = 0, allow_statman = 0;
	printf("\n是否设为超级管理员\n");
	if (!scanf("%d", &is_super)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	if (is_super){
		allow_cardman = 1, allow_billman = 1, allow_shutman = 1, allow_chargeman = 1, allow_statman = 1;
	}
	else {
		printf("\n请赋予管理员权限\n");
		printf("\n格式:permission \n a\t卡管理权限 \n b\t计费标准管理权限 \n m\t上下机管理权限 \n c\t充值退费权限 \n s\t查询统计权限\n f\t输入完成\n");
		printf("\n例如:permission --a b m c s f\n");
		printf("\npermission --");

		fflush(stdin);					//清除读写缓冲区
		while (temp != 'f'){
			scanf("%c", &temp);
			switch (temp){
			case 'a':allow_cardman = 1; break;
			case 'b':allow_billman = 1; break;
			case 'm':allow_shutman = 1; break;
			case 'c':allow_chargeman = 1; break;
			case 's':allow_statman = 1; break;
			case 'f': break;
				default
					:break;
			}
		}
	}
	admin_add_core(user, passwd, is_super, allow_cardman, allow_billman, allow_shutman, allow_chargeman, allow_statman);
	line_breaks(1);
	system("pause");
	return;
}

void purview_man_del_admin(void){
	system("cls");
	print_equals(80);
	line_breaks(1);
	char user[MAX_USER_LEN];
	//	char su_passwd[MAX_PASSWD];
	printf("\n=======删除管理员======\n");
	printf("请输入要删除的管理员的用户名\n");
	if (!scanf("%s", user)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	/*	printf("\n请输入超级管理员密码\n");
	if (!scanf("%s", su_passwd)){
	fflush(stdin);
	printf("\n输入非法！退出");
	*/
	if (admin_has_user(user)){
		admin_del_core(user);
		printf("\n此用户已被删除\n");
	}
	else {
		printf("此用户不存在");
	}
	line_breaks(1);
	system("pause");
	return;
}

void purview_man_configure_permissions(void){
	system("cls");
	print_equals(80);
	line_breaks(1);
	char user[MAX_USER_LEN];
	printf("\n=======修改管理员权限======\n");
	printf("请输入要修改权限的管理员的用户名\n");
	if (!scanf("%s", user)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	printf("\n是否改设为超级管理员\n");
	int is_super =0;
	if (!scanf("%d", &is_super)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	if (is_super){
		admin_set_permission(user, 1, 1);
	}
	else {
		printf("\n请选择要修改的管理员权限\n");
		printf("\n1.卡管理权限\n2.计费标准管理权限 \n3.上下机管理权限 \n 4.充值退费权限 \n 5.查询统计权限\n");
		int value;
		char type;
		scanf("%d", &value);
		switch (value){
		case 1:type = 'a'; break;
		case 2:type = 'b'; break;
		case 3:type = 'm'; break;
		case 4:type = 'c'; break;
		case 5:type = 's'; break;
		default:type = 0; break;
		}
		fflush(stdin);
		printf("\n请问要开启或关闭该权限\n");
		printf("\n0.关闭\n1.开启 \n");
		scanf("%d", &value);
		fflush(stdin);
		if (value != 1 && value != 0)
			type = 0;
		if (!type)
			admin_set_permission(user, type, value);
		else
			printf("/n 您的输入有误，请重新输入 /n");
	}
	line_breaks(1);
	system("pause");
	return;
}

void menu_purview_man_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':purview_man_add_admin();
		break;
	case'2':purview_man_del_admin();
		break;
	case'3':purview_man_configure_permissions();
		break;
	default:menu_wrong_prompt(); purview_man_menu();
		break;
	}
}
