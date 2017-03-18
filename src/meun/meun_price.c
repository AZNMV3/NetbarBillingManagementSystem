#include "../menu.h"


void price_menu(void);
void price_option(void);
void price_head(void);
void price_content(void);
void menu_price_jump(void);

void price_add_a_billing_standards(void);		//菜单——新增计费标准
void price_check_a_billing_standards(void);	//菜单——查询计费标准
void price_del_a_billing_standard(void);		//菜单——删除计费标准
void price_modify_a_billing_standard(void);	//菜单——修改计费标准

void price_menu(void) {
	system("cls");
	system("color 70");
	price_head();
	line_breaks(1);
	price_option();
	line_breaks(1);
	prompt_input();
	menu_price_jump();
}

void price_head(void) {
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	price_content();
	line_breaks(2);
	print_equals(80);
}

void price_content(void) {
	puts_center("欢迎使用本网吧计费管理系统————计费标准管理");
	line_breaks(1);
	puts_center("在计费标准管理您可以新增、查询、删除、修改计费标准。");
	line_breaks(1);
}

void price_option(void) {
	printf("【1.新增计费标准】\t【2.查询计费标准】\t【3.删除计费标准】\t");
	line_breaks(1);
	printf("\t【4.修改计费标准】\t\t【0.返回】\t");
}

void price_add_a_billing_standards(void) {

}

void price_check_a_billing_standards(void) {

}

void price_del_a_billing_standard(void) {

}

void price_modify_a_billing_standard(void) {

}

void menu_price_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':index_menu();
		break;
	case '1':price_add_a_billing_standards();
		break;
	case'2':price_check_a_billing_standards();
		break;
	case'3':price_del_a_billing_standard();
		break;
	case'4':price_modify_a_billing_standard();
		break;
	default:menu_wrong_prompt(); price_menu();
		break;
	}
}