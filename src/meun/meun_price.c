#include "../menu.h"
#include "../price.h"


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
	int time_left_interval, time_right_interval;
	float hour, price;
	printf("\n������۸���������\n");
	printf("\n������۸�ʼ����(��λ:Сʱ������������С�������λ��\n");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	printf("\n������۸��������(��λ:Сʱ������������С�������λ��\n");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	printf("\n������۸�(��λ:Ԫ,�����������֣�\n");
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
	printf("\n������Ҫɾ���۸�ļ۸�ʼ����(��λ:Сʱ������������С�������λ��\n");
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
	printf("\n������Ҫ�޸ĵļ۸�ʼ����(��λ:Сʱ������������С�������λ��\n");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	printf("\n�������µļ۸��������(��λ:Сʱ������������С�������λ��\n");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	printf("\n�������¼۸�(��λ:Ԫ,�����������֣�\n");
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