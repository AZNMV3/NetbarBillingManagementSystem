#include "../menu.h"
#include "../price.h"
#include "../card.h"
#include "../login.h"


void on_and_shut_menu(void){
	while (true){
		system("cls");
		system("color 1f");
		on_and_shut_head();
		line_breaks(1);
		on_and_shut_option();
		line_breaks(2);
		prompt_input();
		menu_on_and_shut_jump();
	}
}

void on_and_shut_head(void){
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	on_and_shut_content();
	line_breaks(1);
	print_equals(80);
}

void on_and_shut_content(void){
	puts_center("欢迎使用本网吧计费管理系统————上下机");
	line_breaks(1);
	puts_center("在计费管理您可以输入卡号上机或进行下机结算。");
	line_breaks(2);
}

void on_and_shut_option(void){
	printf("\t【1.上机】\t【2.下机】\t【0.返回】\t");
}


void on_and_shut_power_on(void){
	char id[MAX_ID];
	char *passwd;
	//	char str[25];
	printf("\n请输入卡号\n");
	scanf("%s", id);
	passwd = win_getpass("\n请输入密码\n");
	if(!card_has(id)){
		printf("卡号或密码错误");
	}else{
		if (can_card_login(id, passwd))
			write_login(time_sec(), id);
		else
		printf("卡号或密码错误");
	}
	system("pause");
	return;
}

void on_and_shut_power_off(void){
	char id[MAX_ID];
	char temp[MAX_PASSWD];
	printf("\n请输入卡号\n");
	scanf("%s", id);
	if(card_has(id)){
		shut_core(id);
		printf("\n下机成功！?您的卡余额为%.2f", card_get_json_value(id,temp));
	}else {
		puts("账号不存在，请检查输入！");
	}
	system("pause");
	return;
}

void menu_on_and_shut_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':on_and_shut_power_on();
		break;
	case'2':on_and_shut_power_off();
		break;
	default:menu_wrong_prompt(); on_and_shut_menu();
		break;
	}
}
