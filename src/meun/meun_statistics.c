#include "../menu.h"
#include "../card.h"
#include "../price.h"
#include <errno.h>

void statistics_menu(void)
{
	while (true) {
		system("cls");
		system("color F0");
		statistics_head();
		line_breaks(1);
		statistics_option();
		line_breaks(2);
		prompt_input();
		menu_statistics_jump();
	}
}

void statistics_head(void)
{
	print_equals(80); //��ӡ��=������ 
	line_breaks(1);
	statistics_content();
	line_breaks(2);
	print_equals(80);
}

void statistics_content(void)
{
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������ͳ�Ʋ�ѯ");
	line_breaks(1);
	puts_center("�ڲ�ѯͳ�������Բ�ѯָ������һ��ʱ���ڵ����Ѽ�¼������ͳ����Ӫҵ�����Ӫҵ��");
	line_breaks(1);
}

void statistics_option(void)
{
	printf("\t��1.��ѯ���Ѽ�¼��\t��2.ͳ����Ӫҵ�\t��3.ͳ����Ӫҵ�\t��0.���ء�\t");
}

void statistics_transactions(void)
{
	system("cls");
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	printf("\n=======��ѯ���Ѽ�¼======\n");
	puts("������Ҫ��ѯ�Ŀ���");
	if (scanf("%s", id) < 1) {
		printf("\n����Ƿ����˳�");
		_getch();
		fflush(stdin);
		return;
	}
	if (card_has(id))
		statistics_print_out_an_user(id);
	else
		puts("���û�������");

	line_breaks(2);
	system("pause");
	return;
}

void statistics_total_turnover(void)
{
	system("cls");
	print_equals(80);
	line_breaks(1);
	float sum;
	int time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day;
	printf("\n=======��ѯӪҵ��======\n");
	puts("\n�����뿪ʼ����");
	puts("��ʽ:�� �� ��");
	if (!scanf("%d%d%d", &time_left_year, &time_left_month, &time_left_day)) {
		puts("\n����Ƿ����˳�");
		_getch();
		fflush(stdin);
		return;
	}

	puts("\n�������������");
	puts("��ʽ:�� �� ��");
	if (!scanf("%d%d%d", &time_right_year, &time_right_month, &time_right_day)) {
		puts("\n����Ƿ����˳�");
		_getch();
		fflush(stdin);
		return;
	}

	ULONGLONG start_time = GetTickCount64();
	int temp = 0;
	sum = statistics_between(time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day, &temp);
	printf("�� %d��%d��%d�� -- %d��%d��%d�� ��Ӫҵ��Ϊ %.2f Ԫ��", time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day, sum);

	ULONGLONG stop_time = GetTickCount64();
	line_breaks(2);
	print_equals(80);
	printf("\n��ѯ��ʱ %lldms", stop_time - start_time);
	system("pause");
	return;
}

void statistics_monthly_turnover(void)
{
	system("cls");
	print_equals(80);
	line_breaks(1);
	FILE* fp;
	statistics_print_out_an_month();
	if ((fp = fopen(MONTH_STAT_FILE_POSITION, "r")) == NULL) {
		puts("Open Failed.");
		printf("error value: %d, %s\n", errno, strerror(errno));
		return;
	}
	int c;
	while ((c = fgetc(fp)) != EOF) putchar(c);
	fclose(fp);
	line_breaks(2);
	print_equals(80);
	system("pause");
}

void menu_statistics_jump(void)
{
	char input = _getch();
	fflush(stdin);
	switch (input) {
		case '0': index_menu();
			break;
		case ' ': index_menu();
			break;
		case 8: index_menu(); //8--BACKSPACE
			break;
		case '1': statistics_transactions();
			break;
		case'2': statistics_total_turnover();
			break;
		case'3': statistics_monthly_turnover();
			break;
		default: menu_wrong_prompt();
			statistics_menu();
			break;
	}
}
