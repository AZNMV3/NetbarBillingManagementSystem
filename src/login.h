/* login.h */
#ifndef LOGIN_H
#define LOGIN_H

/* Head Files */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/*CARD_LOGIN*/
extern void write_login(int time, const char *id);
extern void access_out(char id[]);
extern int start_time_get(char id[]);
extern void shut_core(char id[]);
extern void del_after(char id[]);
extern int time_sec(void);
extern void shut_log(char id[], int ago, float cost_money);

/*ADMIN_LOGIN*/
extern int admin_login(void);
extern char* win_getpass(const char* prompt);
void now_login_admin_permissions(char user[]);

#endif
