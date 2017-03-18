#include "../menu.h"



void index_menu(void);
void index_option(void);
void index_head(void);
void index_content(void);
void menu_index_jump(void);


void index_menu(void) {
	system("cls");
	system("color 3f");
	index_head();
	line_breaks(1);
	index_option();
	line_breaks(1);
	prompt_input();
	menu_index_jump();
}

void index_head(void) {
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	index_content();
	line_breaks(1);
	print_equals(80);
}

void index_content(void) {
	puts_center("欢迎使用本网吧计费管理系统");
	line_breaks(1);
	puts_center("本系统由卡管理、计费标准管理、上下机管理、费用管理、");
	puts_center("查询统计和权限管理模块组成。");
	line_breaks(1);
}

void index_option(void) {
	printf("\t【1.卡管理】\t【2.计费标准】\t【3.上下机】\t【4.费用管理】\t");
	line_breaks(1);
	printf("\t【5.统计查询】\t【6.权限管理】\t\t【0.登出】\t");
}

void menu_index_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':exit(0);
		break;
	case '1':card_man_menu();
		break;
	case'2':price_menu();
		break;
	case'3':on_and_shut_menu();
		break;
	case '4':balance_man_menu();
		break;
	case '5':statistics_menu();
		break;
	case '6':purview_man_menu();
		break;
	default:menu_wrong_prompt(); index_menu();
		break;
	}
}
