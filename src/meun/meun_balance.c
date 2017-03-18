#include "../menu.h"


void balance_man_menu(void);
void balance_man_option(void);
void balance_man_head(void);
void balance_man_content(void);
void menu_balance_jump(void);

void balance_man_top_up(void);				//�˵�������ֵ
void balance_man_withdraw(void);			//�˵���������


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
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	balance_man_content();
	line_breaks(1);
	print_equals(80);
}

void balance_man_content(void) {
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������������");
	line_breaks(1);
	puts_center("�ڷ��ù��������Ը�һ���Ѿ����ڵĿ����г�ֵ�򽫿������ظ��û���");
	line_breaks(2);
}

void balance_man_option(void) {
	printf("\t��1.��ֵ��\t��2.�˷ѡ�\t��0.���ء�\t");
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
