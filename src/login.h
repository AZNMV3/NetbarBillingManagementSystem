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
#include <stdbool.h>

#define CARD_LOGIN_FILE_POSITION "./data/login.txt"
#define CARD_LOG				"./data/log.txt"

/*CARD_LOGIN*/
extern void write_login(int time, const char *id);
//extern void access_out(char id[]);
extern int start_time_get(char id[]);
extern void shut_core(char id[]);
extern void del_after(char id[]);
extern int time_sec(void);
extern void shut_log(char id[], int ago, double cost_money);

/*ADMIN_LOGIN*/
extern bool admin_login(void);
extern char* win_getpass(const char* prompt);
extern void now_login_admin_permissions(char user[]);

extern bool is_admin_file_exist(void);
#endif
