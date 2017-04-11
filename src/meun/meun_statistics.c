#include "../menu.h"
#include "../card.h"
#include "../price.h"


void statistics_menu(void);				//�˵�������ѯͳ��ģ�����˵�
void statistics_option(void);				//�˵�����ѡ��
void statistics_head(void);				//�˵�����ͷ��
void statistics_content(void);				//�˵�������ӭ��Ϣ
void menu_statistics_jump(void);

void statistics_transactions(void);		//�˵�������ѯ���Ѽ�¼
void statistics_total_turnover(void);		//�˵�����ͳ����Ӫҵ��
void statistics_monthly_turnover(void);	//�˵�--ͳ����Ӫҵ��


void statistics_menu(void) {
	system("cls");
	system("color F0");
	statistics_head();
	line_breaks(1);
	statistics_option();
	line_breaks(2);
	prompt_input();
	menu_statistics_jump();
}

void statistics_head(void) {
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	statistics_content();
	line_breaks(2);
	print_equals(80);
}

void statistics_content(void) {
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������ͳ�Ʋ�ѯ");
	line_breaks(1);
	puts_center("�ڲ�ѯͳ�������Բ�ѯָ������һ��ʱ���ڵ����Ѽ�¼������ͳ����Ӫҵ�����Ӫҵ��");
	line_breaks(1);
}

void statistics_option(void) {
	printf("\t��1.��ѯ���Ѽ�¼��\t��2.ͳ����Ӫҵ�\t��3.ͳ����Ӫҵ�\t��0.���ء�\t");
}

void statistics_transactions(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	printf("\n=======��ѯ���Ѽ�¼======\n");
	puts("������Ҫ��ѯ�Ŀ���");
	if (!scanf("%s", id)) {
		printf("\n����Ƿ����˳�");
		return;
	}
	if (card_has(id)) {
		statistics_print_out_an_user(id);
	}
	else {
		puts("���û�������");
	}
	line_breaks(2);
	system("pause");
	statistics_menu();
}

void statistics_total_turnover(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);
	float sum;
	int time_left_year, time_left_month, time_left_day ,time_right_year, time_right_month, time_right_day;
	printf("\n=======��ѯӪҵ��======\n");
	puts("\n�����뿪ʼ����");
	puts("��ʽ:�� �� ��");
	if(!scanf("%d%d%d", &time_left_year,&time_left_month,&time_left_day)) {
		puts("\n����Ƿ����˳�");
		return;
	}

	puts("\n�������������");
	puts("��ʽ:�� �� ��");
	if (!scanf("%d%d%d", &time_right_year, &time_right_month, &time_right_day)) {
		puts("\n����Ƿ����˳�");
		return;
	}

	sum = statistics_between(time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day);
	printf("�� %d��%d��%d�� -- %d��%d��%d�� ��Ӫҵ��Ϊ %.2f Ԫ��", time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day, sum);

	line_breaks(2);
	system("pause");
	statistics_menu();
}

void statistics_monthly_turnover(void) {

}

void menu_statistics_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':index_menu();
		break;
	case '1':statistics_transactions();
		break;
	case'2':statistics_total_turnover();
		break;
	case'3':statistics_monthly_turnover();
		break;
	default:menu_wrong_prompt(); statistics_menu();
		break;
	}
}
