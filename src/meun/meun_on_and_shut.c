#include "../menu.h"
#include "../price.h"

void login_in(void);
void on_and_shut_menu(void);
void on_and_shut_option(void);
void on_and_shut_head(void);
void on_and_shut_content(void);
void menu_on_and_shut_jump(void);

void on_and_shut_power_on(void);				//菜单——上机
void on_and_shut_power_off(void);				//菜单——下机


void on_and_shut_menu(void) {
	system("cls");
	system("color 1f");
	on_and_shut_head();
	line_breaks(1);
	on_and_shut_option();
	line_breaks(2);
	prompt_input();
	menu_on_and_shut_jump();
}

void on_and_shut_head(void) {
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	on_and_shut_content();
	line_breaks(1);
	print_equals(80);
}

void on_and_shut_content(void) {
	puts_center("欢迎使用本网吧计费管理系统————上下机");
	line_breaks(1);
	puts_center("在计费管理您可以输入卡号上机或进行下机结算。");
	line_breaks(2);
}

void on_and_shut_option(void) {
	printf("\t【1.上机】\t【2.下机】\t【0.返回】\t");
}


void on_and_shut_power_on(void) {
	login_in();
}

void on_and_shut_power_off(void) {

}

void menu_on_and_shut_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':index_menu();
		break;
	case '1':on_and_shut_power_on();
		break;
	case'2':on_and_shut_power_off();
		break;
	default:menu_wrong_prompt(); on_and_shut_menu();
		break;
	}
}
