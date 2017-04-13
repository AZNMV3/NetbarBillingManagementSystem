#include "../menu.h"
#include "../card.h"


void card_man_menu(void){
	while (true) {
		system("cls");
		system("color 6f");
		card_man_head();
		line_breaks(1);
		card_man_option();
		line_breaks(2);
		prompt_input();
		menu_card_man_jump();
	}
}

void card_man_head(void){
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	card_man_content();
	line_breaks(2);
	print_equals(80);
}

void card_man_content(void){
	puts_center("欢迎使用本网吧计费管理系统————卡管理");
	line_breaks(1);
	puts_center("在卡管理您可以执行添加卡、查询卡、删除卡操作。");
	line_breaks(1);
}

void card_man_option(void){
	printf("\t【1.添加卡】\t【2.查询卡】\t【3.删除卡】\t【0.返回】\t");
}

void card_man_add(void){
	system("cls");
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	char passwd[MAX_PASSWD];
	float balance = 0;
	printf("\n=======添加卡======\n");
	printf("请输入身份证号或护照号(即卡号)\n");
	if (!scanf("%s", id)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	puts("\n请输入卡密码");
	if (!scanf("%s", passwd)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}

	puts("\n请输入开卡金额");
	if (!scanf("%f", &balance)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}
	card_add_core(id, passwd, balance);
	line_breaks(1);
	system("pause");
	return;
}

void card_get_information(void){
	system("cls");
	print_equals(80);		
	line_breaks(1);
	float balance = 0;
	char id[MAX_ID];
	char passwd[MAX_PASSWD];

	puts("请输入要查询的卡号\n");
	if (!scanf("%s", id)){
		printf("\n输入非法！退出");
		return;
	}
	ULONGLONG start_time = GetTickCount64();
	if (card_has(id))
		balance = card_get_json_value(id, passwd);
	else{
		line_breaks(2);
		printf("此用户不存在");
		line_breaks(2);
		system("pause");
		card_man_menu();
	}
	system("cls");
	print_equals(80);
	line_breaks(1);
	print_equals(60);
	printf("\n查询结果\n");
	print_equals(60);
	printf("\n卡号\t\t密码\t\t余额");
	line_breaks(1);
	print_equals(60);
	line_breaks(1);
	printf("%s\t%s\t\t\t%.2f",id,passwd,balance);
	ULONGLONG stop_time = GetTickCount64();
	line_breaks(2);
	print_equals(80);
	printf("\n查询耗时 %lldms", stop_time - start_time);
	line_breaks(2);
	system("pause");
	return;
}

void card_man_del(void){
	system("cls");
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	char temp[MAX_PASSWD];
	printf("\n=======删卡退费======\n");
	puts("请输入要删除的卡号\n");
	if (!scanf("%s", id)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}

	if (card_has(id)){
		float balance = card_get_json_value(id, temp);
		card_del_core(id);
		printf("\n此用户已被删除\n");
		printf("\n应退费%f元\n", balance);
	}
	else {
		printf("此用户不存在");
	}
	line_breaks(2);
	system("pause");
	return;
}

void menu_card_man_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':card_man_add();
		break;
	case'2':card_get_information();
		break;
	case'3':card_man_del();
		break;
	default:menu_wrong_prompt(); card_man_menu();
		break;
	}
}