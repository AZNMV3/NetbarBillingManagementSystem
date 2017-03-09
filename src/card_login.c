#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "card.h"

void login_in(void) {
	char id[MAX_ID];
	char passwd[MAX_PASSWD];
	printf("\n«Î ‰»Îø®∫≈\n");
	scanf("%s", id);
	printf("\n«Î ‰»Î√‹¬Î\n");
	scanf("%s", passwd);
	can_card_login(id, passwd);
}
