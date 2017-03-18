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
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	index_content();
	line_breaks(1);
	print_equals(80);
}

void index_content(void) {
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ");
	line_breaks(1);
	puts_center("��ϵͳ�ɿ������Ʒѱ�׼�������»��������ù���");
	puts_center("��ѯͳ�ƺ�Ȩ�޹���ģ����ɡ�");
	line_breaks(1);
}

void index_option(void) {
	printf("\t��1.������\t��2.�Ʒѱ�׼��\t��3.���»���\t��4.���ù���\t");
	line_breaks(1);
	printf("\t��5.ͳ�Ʋ�ѯ��\t��6.Ȩ�޹���\t\t��0.�ǳ���\t");
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
