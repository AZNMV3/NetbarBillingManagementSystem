/* admin.h */
#ifndef ADMIN_H
#define ADMIN_H

#define MAX_ID 12
#define MAX_PASSWD 30

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./include/cJSON.h"

#define FILE_POSITION "../data/admin.json"

struct admin {
	char user[MAX_ID];
	char password[MAX_PASSWD];
	int is_super;
	int allow_cardman;
	int allow_billman;
	int allow_shutman;
	int allow_chargeman;
	int allow_statman;
};

extern void admin_get_information(void);
extern int admin_get_permission(char * user, char type);
extern void admin_set_permission(char *name, char type, int new_vaule);

extern int admin_add_core(char user[], char password[], int is_super, int allow_cardman, int allow_billman, int allow_shutman, int allow_chargeman, int allow_statman);
extern void admin_get_json_value(char name[], char password[], int *is_super, int *allow_cardman, int *allow_billman, int *allow_shutman, int *allow_chargeman, int *allow_statman);
extern void admin_del_core(char name[]);
extern int admin_has_user(char name[]);
extern int admin_is_passwd_right(char name[], char password[]);
extern void admin_set_password(char name[], char newpasswd[]);


#endif
