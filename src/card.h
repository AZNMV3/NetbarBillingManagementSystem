/* card.h */
#ifndef CARD_H
#define CARD_H

#define MAX_ID 19
#define MAX_PASSWD 30

struct card {
	char id[MAX_ID];
	char passwd[MAX_PASSWD];
	float balance;
};

void card_add();
void card_del();
void card_get_information(void);

int card_add_core(char id[], char password[], float balance);
float card_get_json_value(char id[], char password[]);
void card_del_core(char id[]);
int card_has(char id[]);
int card_is_passwd_right(char id[], char password[]);
void top_up(char id[], float money);
void cost(char id[], float money);
int	can_card_login(char id[], char passwd[]);
#endif
