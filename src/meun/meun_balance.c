#include "../menu.h"


void balance_man_menu(void);
void balance_man_option(void);
void balance_man_head(void);
void balance_man_content(void);
void menu_balance_jump(void);

void balance_man_top_up(void);				//菜单——充值
void balance_man_withdraw(void);			//菜单——提现


void balance_man_menu(void) {
	system("cls");
	system("color 5f");
	balance_man_head();
	line_breaks(1);
	balance_man_option();
	line_breaks(2);
	prompt_input();
	menu_balance_jump();
}

void balance_man_head(void) {
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	balance_man_content();
	line_breaks(1);
	print_equals(80);
}

void balance_man_content(void) {
	puts_center("欢迎使用本网吧计费管理系统————余额管理");
	line_breaks(1);
	puts_center("在费用管理您可以给一张已经存在的卡进行充值或将卡中余额返回给用户。");
	line_breaks(2);
}

void balance_man_option(void) {
	printf("\t【1.充值】\t【2.退费】\t【0.返回】\t");
}


void balance_man_top_up(void) {

}

void balance_man_withdraw(void) {

}

void menu_balance_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':index_menu();
		break;
	case '1':balance_man_top_up();
		break;
	case'2':balance_man_withdraw();
		break;
	default:menu_wrong_prompt(); balance_man_menu();
		break;
	}
}
