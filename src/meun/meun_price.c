#include "../menu.h"
#include "../price.h"



void price_menu(void){
	while (true) {
		system("cls");
		system("color 70");
		price_head();
		line_breaks(1);
		price_option();
		line_breaks(1);
		prompt_input();
		menu_price_jump();
	}
}

void price_head(void){
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	price_content();
	line_breaks(2);
	print_equals(80);
}

void price_content(void){
	puts_center("欢迎使用本网吧计费管理系统————计费标准管理");
	line_breaks(1);
	puts_center("在计费标准管理您可以新增、查询、删除、修改计费标准。");
	line_breaks(1);
}

void price_option(void){
	printf("\t【1.新增计费标准】\t【2.查询计费标准】\t【3.删除计费标准】\t");
	line_breaks(1);
	printf("\t【4.修改计费标准】\t\t\t\t【0.返回】\t");
}

void price_add_a_billing_standards(void){
	int time_left_interval, time_right_interval;
	float hour, price; 
	system("cls");
	print_equals(80);
	line_breaks(1);
	puts("\n=======新增计费标准======");
	puts("您需要输入一个计费周期开始的时间和该计费周期结束的时间.");
	puts("eg 1 2 3.2 代表上机在1-2小时之内时每小时计费3.2元");
	puts("\n请输入价格开始区间(单位:小时，可以输入至小数点后两位）");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	puts("\n请输入价格结束区间(单位:小时，可以输入至小数点后两位)");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	puts("\n请输入价格(单位:元,可以输入至分)");
	scanf("%f", &price);
	price_add_core(time_left_interval, time_right_interval, price);
	line_breaks(2);
	system("pause");
}

void price_check_a_billing_standards(void){
	float hour;
	int time;
	puts("\n请输入上机时间(单位:小时，可以输入至小数点后两位)");
	scanf("%f", &hour);
	time = (int)(1.0 * hour * 3600);
	float price = price_read(time);
	
	printf("该时间每小时应付费用为%.2f元\n", price);
	printf("预计应付%.2f元", price*hour);
	line_breaks(2);
	system("pause");
	return;
}

void price_del_a_billing_standard(void){
	float hour;
	puts("\n请输入要删除价格的价格开始区间(单位:小时，可以输入至小数点后两位)");
	scanf("%f", &hour);
	int time_left_interval = (int)(1.0 * hour * 3600);;
	price_del_core(time_left_interval);
	line_breaks(2);
	system("pause");
	return;
}

void price_modify_a_billing_standard(void){
	int time_left_interval, time_right_interval;
	float hour, price;
	puts("\n请输入要修改的价格开始区间(单位:小时，可以输入至小数点后两位）");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	puts("\n请输入新的价格结束区间(单位:小时，可以输入至小数点后两位）");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	puts("\n请输入新价格(单位:元,可以输入至分)");
	scanf("%f", &price);
	price_del_core(time_left_interval);
	price_add_core(time_left_interval, time_right_interval, price);
	line_breaks(2);
	system("pause");
	return;
}

void menu_price_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
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