/* card.h */
#ifndef CARD_H
#define CARD_H

#define MAX_ID 19
#define MAX_PASSWD 30
#define MIN_CAN_LOGIN_BALANCE 0.40
/* Head Files */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./include/cJSON.h"
#include <stdbool.h>


#define FILE_NAME "./data/card.json"

struct card {
	char id[MAX_ID];
	char passwd[MAX_PASSWD];
	float balance;
};

extern int card_add_core(char id[], char password[], float balance);
extern float card_get_json_value(char id[], char password[]);
extern void card_del_core(char id[]);
extern bool card_has(char id[]);
extern bool card_is_passwd_right(char id[], char password[]);
extern void top_up(char id[], float money);
extern void cost(char id[], float money);
extern bool	can_card_login(char id[], char passwd[]);
#endif
