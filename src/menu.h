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


/* ���ܺ��� */
extern void puts_center(const char* txt);
extern void print_equals(int num);
extern void line_breaks(int num);
extern void prompt_input(void);
extern void menu_wrong_prompt(void);
extern void menu_index_jump(void);
extern void menu_no_permission_prompt(void);

/* menu������ */
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

extern void card_man_add(void);			//�˵�������ӿ�
extern void card_get_information(void);	//�˵�������ѯ��
extern void card_man_del(void);			//�˵�--ɾ����

/* meun_purview_man.c */
extern void purview_man_menu(void);
extern void purview_man_option(void);
extern void purview_man_head(void);
extern void purview_man_content(void);
extern void menu_purview_man_jump(void);

extern void purview_man_add_admin(void);					//�˵�������ӹ���Ա
extern void purview_man_del_admin(void);					//�˵�����ɾ������Ա
extern void purview_man_configure_permissions(void);		//�˵���������Ȩ��

/* meun_on_and_shut.c */
extern void on_and_shut_menu(void);
extern void on_and_shut_option(void);
extern void on_and_shut_head(void);
extern void on_and_shut_content(void);
extern void menu_on_and_shut_jump(void);

extern void on_and_shut_power_on(void);				//�˵������ϻ�
extern void on_and_shut_power_off(void);				//�˵������»�

/* meun_balance.c */
extern void balance_man_menu(void);
extern void balance_man_option(void);
extern void balance_man_head(void);
extern void balance_man_content(void);
extern void menu_balance_jump(void);

extern void balance_man_top_up(void);				//�˵�������ֵ
extern void balance_man_withdraw(void);			//�˵���������

/* meun_index.c */
extern void index_menu(void);
extern void index_option(void);
extern void index_head(void);
extern void index_content(void);
extern void menu_index_jump(void);
extern bool can_user_enter(char type);

/* meun_statistics.c */
extern void statistics_menu(void);				//�˵�������ѯͳ��ģ�����˵�
extern void statistics_option(void);				//�˵�����ѡ��
extern void statistics_head(void);				//�˵�����ͷ��
extern void statistics_content(void);				//�˵�������ӭ��Ϣ
extern void menu_statistics_jump(void);

extern void statistics_transactions(void);		//�˵�������ѯ���Ѽ�¼
extern void statistics_total_turnover(void);		//�˵�����ͳ����Ӫҵ��
extern void statistics_monthly_turnover(void);	//�˵�--ͳ����Ӫҵ��

/* meun_price.c */
extern void price_menu(void);
extern void price_option(void);
extern void price_head(void);
extern void price_content(void);
extern void menu_price_jump(void);

extern void price_add_a_billing_standards(void);		//�˵����������Ʒѱ�׼
extern void price_check_a_billing_standards(void);	//�˵�������ѯ�Ʒѱ�׼
extern void price_del_a_billing_standard(void);		//�˵�����ɾ���Ʒѱ�׼
extern void price_modify_a_billing_standard(void);	//�˵������޸ļƷѱ�׼
#endif
