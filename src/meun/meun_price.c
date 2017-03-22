#include "../menu.h"
#include "../price.h"


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
	line_breaks(2);
	system("pause");
	price_menu();
}

void price_check_a_billing_standards(void) {





	line_breaks(2);
	system("pause");
	price_menu();
}

void price_del_a_billing_standard(void) {
	float hour;
	printf("\n请输入要删除价格的价格开始区间(单位:小时，可以输入至小数点后两位）\n");
	scanf("%f", &hour);
	int time_left_interval = (int)(1.0 * hour * 3600);;
	price_del_core(time_left_interval);
	line_breaks(2);
	system("pause");
	price_menu();
}

void price_modify_a_billing_standard(void) {
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
	line_breaks(2);
	system("pause");
	price_menu();
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