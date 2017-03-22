/* login.h */
#ifndef LOGIN_H
#define LOGIN_H

/* Head Files */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

/*CARD_LOGIN*/
extern void write_login(int time, const char *id);
extern void login_in(void);
extern void access_out(char id[]);
extern int start_time_get(char id[]);
extern void shut_core(char id[]);
extern void del_after(char id[]);

/*ADMIN_LOGIN*/
int admin_login(void);
char* win_getpass(const char* prompt);

#endif
