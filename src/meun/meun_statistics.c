#include "../menu.h"


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
	FILE *fp = fopen("./data/log.txt", "r");
	int c;
	while ((c = fgetc(fp)) != EOF) putchar(c);
	fclose(fp);
}

void statistics_total_turnover(void) {

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
