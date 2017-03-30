#include "../menu.h"


void statistics_menu(void);				//菜单——查询统计模块主菜单
void statistics_option(void);				//菜单——选项
void statistics_head(void);				//菜单——头部
void statistics_content(void);				//菜单——欢迎信息
void menu_statistics_jump(void);

void statistics_transactions(void);		//菜单——查询消费记录
void statistics_total_turnover(void);		//菜单——统计总营业额
void statistics_monthly_turnover(void);	//菜单--统计月营业额


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
