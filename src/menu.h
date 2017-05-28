/* menu.h */
#ifndef MENU_H
#define MENU_H

/* Head Files */
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h> 
#include <conio.h> 
#include <time.h> 
#include <stdbool.h>


/* 功能函数 */
extern void puts_center(const char* txt);
extern void print_equals(int num);
extern void line_breaks(int num);
extern void prompt_input(void);
extern void menu_wrong_prompt(void);
extern void menu_index_jump(void);
extern void menu_no_permission_prompt(void);

/* menu主函数 */
extern void index_menu(void);
extern void card_man_menu(void);
extern void price_menu(void);
extern void on_and_shut_menu(void);
extern void balance_man_menu(void);
extern void statistics_menu(void);
extern void statistics_menu(void);
extern void purview_man_menu(void);

/* meun_card_man.c */
extern void card_man_menu(void);
extern void card_man_option(void);
extern void card_man_head(void);
extern void card_man_content(void);
extern void menu_card_man_jump(void);

extern void card_man_add(void);			//菜单——添加卡
extern void card_get_information(void);	//菜单——查询卡
extern void card_man_del(void);			//菜单--删除卡

/* meun_purview_man.c */
extern void purview_man_menu(void);
extern void purview_man_option(void);
extern void purview_man_head(void);
extern void purview_man_content(void);
extern void menu_purview_man_jump(void);

extern void purview_man_add_admin(void);					//菜单——添加管理员
extern void purview_man_del_admin(void);					//菜单——删除管理员
extern void purview_man_configure_permissions(void);		//菜单——配置权限

/* meun_on_and_shut.c */
extern void on_and_shut_menu(void);
extern void on_and_shut_option(void);
extern void on_and_shut_head(void);
extern void on_and_shut_content(void);
extern void menu_on_and_shut_jump(void);

extern void on_and_shut_power_on(void);				//菜单——上机
extern void on_and_shut_power_off(void);				//菜单——下机

/* meun_balance.c */
extern void balance_man_menu(void);
extern void balance_man_option(void);
extern void balance_man_head(void);
extern void balance_man_content(void);
extern void menu_balance_jump(void);

extern void balance_man_top_up(void);				//菜单——充值
extern void balance_man_withdraw(void);			//菜单——提现

/* meun_index.c */
extern void index_menu(void);
extern void index_option(void);
extern void index_head(void);
extern void index_content(void);
extern void menu_index_jump(void);
extern bool can_user_enter(char type);

/* meun_statistics.c */
extern void statistics_menu(void);				//菜单——查询统计模块主菜单
extern void statistics_option(void);				//菜单——选项
extern void statistics_head(void);				//菜单——头部
extern void statistics_content(void);				//菜单——欢迎信息
extern void menu_statistics_jump(void);

extern void statistics_transactions(void);		//菜单——查询消费记录
extern void statistics_total_turnover(void);		//菜单——统计总营业额
extern void statistics_monthly_turnover(void);	//菜单--统计月营业额

/* meun_price.c */
extern void price_menu(void);
extern void price_option(void);
extern void price_head(void);
extern void price_content(void);
extern void menu_price_jump(void);

extern void price_add_a_billing_standards(void);		//菜单——新增计费标准
extern void price_check_a_billing_standards(void);	//菜单——查询计费标准
extern void price_del_a_billing_standard(void);		//菜单——删除计费标准
extern void price_modify_a_billing_standard(void);	//菜单——修改计费标准
#endif
