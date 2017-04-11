/* menu.h */
#ifndef MENU_H
#define MENU_H

/* Head Files */
#include <stdio.h> 
#include <stdlib.h>
#include <tchar.h> 
#include <conio.h> 
#include <time.h> 
#include <stdbool.h>

/*
const WORD FORE_BLUE = FOREGROUND_BLUE;           //蓝色文本属性  
const WORD FORE_GREEN = FOREGROUND_GREEN;          //绿色文本属性  
const WORD FORE_RED = FOREGROUND_RED;            //红色文本属性  
//const WORD FORE_PURPLE = FORE_BLUE | FORE_RED;      //紫色文本属性  
//const WORD FORE_CYAN = FORE_BLUE | FORE_GREEN;    //青色文本属性  
//const WORD FORE_YELLOW = FORE_RED | FORE_GREEN;     //黄色文本属性  
const WORD FORE_GRAY = FOREGROUND_INTENSITY;      //灰色文本属性 
*/

/* Time */
#if defined(WIN32)
# define  TIMEB    _timeb
# define  ftime    _ftime
#else
#define TIMEB timeb
#endif

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
void on_and_shut_menu(void);
void on_and_shut_option(void);
void on_and_shut_head(void);
void on_and_shut_content(void);
void menu_on_and_shut_jump(void);

void on_and_shut_power_on(void);				//菜单——上机
void on_and_shut_power_off(void);				//菜单——下机

/* meun_balance.c */
void balance_man_menu(void);
void balance_man_option(void);
void balance_man_head(void);
void balance_man_content(void);
void menu_balance_jump(void);

void balance_man_top_up(void);				//菜单——充值
void balance_man_withdraw(void);			//菜单——提现

/* meun_index.c */
void index_menu(void);
void index_option(void);
void index_head(void);
void index_content(void);
void menu_index_jump(void);
bool can_user_enter(char type);
#endif
