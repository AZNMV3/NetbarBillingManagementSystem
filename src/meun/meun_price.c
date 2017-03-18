#include "../menu.h"


void price_menu(void);
void price_option(void);
void price_head(void);
void price_content(void);
void menu_price_jump(void);

void price_add_a_billing_standards(void);		//�˵����������Ʒѱ�׼
void price_check_a_billing_standards(void);	//�˵�������ѯ�Ʒѱ�׼
void price_del_a_billing_standard(void);		//�˵�����ɾ���Ʒѱ�׼
void price_modify_a_billing_standard(void);	//�˵������޸ļƷѱ�׼

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
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	price_content();
	line_breaks(2);
	print_equals(80);
}

void price_content(void) {
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ���������Ʒѱ�׼����");
	line_breaks(1);
	puts_center("�ڼƷѱ�׼������������������ѯ��ɾ�����޸ļƷѱ�׼��");
	line_breaks(1);
}

void price_option(void) {
	printf("��1.�����Ʒѱ�׼��\t��2.��ѯ�Ʒѱ�׼��\t��3.ɾ���Ʒѱ�׼��\t");
	line_breaks(1);
	printf("\t��4.�޸ļƷѱ�׼��\t\t��0.���ء�\t");
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