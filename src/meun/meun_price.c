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
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	price_content();
	line_breaks(2);
	print_equals(80);
}

void price_content(void){
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ���������Ʒѱ�׼����");
	line_breaks(1);
	puts_center("�ڼƷѱ�׼������������������ѯ��ɾ�����޸ļƷѱ�׼��");
	line_breaks(1);
}

void price_option(void){
	printf("\t��1.�����Ʒѱ�׼��\t��2.��ѯ�Ʒѱ�׼��\t��3.ɾ���Ʒѱ�׼��\t");
	line_breaks(1);
	printf("\t��4.�޸ļƷѱ�׼��\t\t\t\t��0.���ء�\t");
}

void price_add_a_billing_standards(void){
	int time_left_interval, time_right_interval;
	float hour, price; 
	system("cls");
	print_equals(80);
	line_breaks(1);
	puts("\n=======�����Ʒѱ�׼======");
	puts("����Ҫ����һ���Ʒ����ڿ�ʼ��ʱ��͸üƷ����ڽ�����ʱ��.");
	puts("eg 1 2 3.2 �����ϻ���1-2Сʱ֮��ʱÿСʱ�Ʒ�3.2Ԫ");
	puts("\n������۸�ʼ����(��λ:Сʱ������������С�������λ��");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	puts("\n������۸��������(��λ:Сʱ������������С�������λ)");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	puts("\n������۸�(��λ:Ԫ,������������)");
	scanf("%f", &price);
	price_add_core(time_left_interval, time_right_interval, price);
	line_breaks(2);
	system("pause");
}

void price_check_a_billing_standards(void){
	float hour;
	int time;
	puts("\n�������ϻ�ʱ��(��λ:Сʱ������������С�������λ)");
	scanf("%f", &hour);
	time = (int)(1.0 * hour * 3600);
	float price = price_read(time);
	
	printf("��ʱ��ÿСʱӦ������Ϊ%.2fԪ\n", price);
	printf("Ԥ��Ӧ��%.2fԪ", price*hour);
	line_breaks(2);
	system("pause");
	return;
}

void price_del_a_billing_standard(void){
	float hour;
	puts("\n������Ҫɾ���۸�ļ۸�ʼ����(��λ:Сʱ������������С�������λ)");
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
	puts("\n������Ҫ�޸ĵļ۸�ʼ����(��λ:Сʱ������������С�������λ��");
	scanf("%f", &hour);
	time_left_interval = (int)(1.0 * hour * 3600);
	puts("\n�������µļ۸��������(��λ:Сʱ������������С�������λ��");
	scanf("%f", &hour);
	time_right_interval = (int)(1.0 * hour * 3600);
	puts("\n�������¼۸�(��λ:Ԫ,������������)");
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