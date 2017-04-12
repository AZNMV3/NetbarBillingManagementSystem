#include "../menu.h"
#include "../card.h"


void balance_man_menu(void){
	system("cls");
	system("color 5f");
	balance_man_head();
	line_breaks(1);
	balance_man_option();
	line_breaks(2);
	prompt_input();
	menu_balance_jump();
}

void balance_man_head(void){
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	balance_man_content();
	line_breaks(1);
	print_equals(80);
}

void balance_man_content(void){
	puts_center("欢迎使用本网吧计费管理系统————余额管理");
	line_breaks(1);
	puts_center("在费用管理您可以给一张已经存在的卡进行充值或将卡中余额返回给用户。");
	line_breaks(2);
}

void balance_man_option(void){
	printf("\t【1.充值】\t【2.退费】\t【0.返回】\t");
}


void balance_man_top_up(void){
	char id[MAX_ID];
	float money = 0;
	puts("\n=======充值======");
	puts("请输入要充值的卡号");
	if (!scanf("%s", id)){
		fflush(stdin);
		puts("\n输入非法！退出");
		return;
	}
	puts("请输入要充值的金额:");
	if (!scanf("%f", &money)){
		fflush(stdin);
		puts("\n输入非法！退出");
		return;
	}
	if (card_has(id)){
	top_up(id,money);
	char temp[MAX_PASSWD];
	float balance = card_get_json_value(id, temp);
	printf("您已成功充值%.2f元，现在余额为%.2f\n", money, balance);
	}
	else {
		printf("此用户不存在");
	}
	line_breaks(2);
	system("pause");
	balance_man_menu();
}


void balance_man_withdraw(void){
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	char temp[MAX_PASSWD];
	printf("\n=======退费======\n");
	puts("请输入要退费的卡号");
	if (!scanf("%s", id)){
		fflush(stdin);
		printf("\n输入非法！退出");
		return;
	}

	if (card_has(id)){
		float balance = card_get_json_value(id, temp);
		printf("\n应退费%f元，请注意只允许全额退费\n", balance);
		cost(id, balance);
		printf("您已成功退费！");
	}
	else {
		printf("此用户不存在");
	}
	line_breaks(2);
	system("pause");
	balance_man_menu();
}

void menu_balance_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':balance_man_top_up();
		break;
	case'2':balance_man_withdraw();
		break;
	default:menu_wrong_prompt(); balance_man_menu();
		break;
	}
}
