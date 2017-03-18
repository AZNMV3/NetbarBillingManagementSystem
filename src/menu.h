/* menu.h */
#ifndef MENU_H
#define MENU_H

/* Head Files */
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h> 
#include <tchar.h> 
#include <conio.h> 

/*
const WORD FORE_BLUE = FOREGROUND_BLUE;           //蓝色文本属性  
const WORD FORE_GREEN = FOREGROUND_GREEN;          //绿色文本属性  
const WORD FORE_RED = FOREGROUND_RED;            //红色文本属性  
//const WORD FORE_PURPLE = FORE_BLUE | FORE_RED;      //紫色文本属性  
//const WORD FORE_CYAN = FORE_BLUE | FORE_GREEN;    //青色文本属性  
//const WORD FORE_YELLOW = FORE_RED | FORE_GREEN;     //黄色文本属性  
const WORD FORE_GRAY = FOREGROUND_INTENSITY;      //灰色文本属性 
*/

/* 功能函数 */
extern void puts_center(const char* txt);
extern void print_equals(int num);
extern void line_breaks(int num);
extern void prompt_input(void);
extern void menu_wrong_prompt(void);
extern void menu_index_jump(void);

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
#endif
