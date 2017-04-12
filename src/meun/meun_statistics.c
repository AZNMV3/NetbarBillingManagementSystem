#include "../menu.h"
#include "../card.h"
#include "../price.h"


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
	print_equals(80);		//打印‘=’个数 
	line_breaks(1);
	statistics_content();
	line_breaks(2);
	print_equals(80);
}

void statistics_content(void) {
	puts_center("欢迎使用本网吧计费管理系统————统计查询");
	line_breaks(1);
	puts_center("在查询统计您可以查询指定卡在一段时间内的消费记录，可以统计月营业额和总营业额");
	line_breaks(1);
}

void statistics_option(void) {
	printf("\t【1.查询消费记录】\t【2.统计总营业额】\t【3.统计月营业额】\t【0.返回】\t");
}

void statistics_transactions(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	printf("\n=======查询消费记录======\n");
	puts("请输入要查询的卡号");
	if (!scanf("%s", id)) {
		printf("\n输入非法！退出");
		return;
	}
	if (card_has(id)) {
		statistics_print_out_an_user(id);
	}
	else {
		puts("此用户不存在");
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
	printf("\n=======查询营业额======\n");
	puts("\n请输入开始日期");
	puts("格式:年 月 日");
	if(!scanf("%d%d%d", &time_left_year,&time_left_month,&time_left_day)) {
		puts("\n输入非法！退出");
		return;
	}

	puts("\n请输入结束日期");
	puts("格式:年 月 日");
	if (!scanf("%d%d%d", &time_right_year, &time_right_month, &time_right_day)) {
		puts("\n输入非法！退出");
		return;
	}
	
	ULONGLONG start_time = GetTickCount64();
	int temp = 0;
	sum = statistics_between(time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day, &temp);
	printf("从 %d年%d月%d日 -- %d年%d月%d日 的营业额为 %.2f 元。", time_left_year, time_left_month, time_left_day, time_right_year, time_right_month, time_right_day, sum);
	
	ULONGLONG stop_time = GetTickCount64();
	line_breaks(2);
	print_equals(80);
	printf("\n查询耗时 %lldms", stop_time - start_time);
	system("pause");
	statistics_menu();
}

void statistics_monthly_turnover(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);
	FILE*fp;
	statistics_print_out_an_month();
	if ((fp = fopen(MONTH_STAT_FILE_POSITION, "r")) == NULL){
		printf("Open Failed.\n");
		return;
	}
	int c;
	while ((c = fgetc(fp)) != EOF) putchar(c);
	fclose(fp);
	line_breaks(2);
	print_equals(80);
	system("pause");
	statistics_menu();
}

void menu_statistics_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
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
