/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_ID 20
#define MAX_PASSWD 30


long user_num(void) {
	FILE  *fp;
	long card_id;
	int auth;
	char passwd[MAX_PASSWD];
	if ((fp = fopen("./data/card.txt", "r+")) == NULL) {
		printf("Can't Open File!");
		exit(0);
	}
	fseek(fp, -20L, SEEK_END);
	while (1) {
		char ch = getc(fp);
		if (ch = '\n') {
			break;
		}
		fseek(fp, -1L, SEEK_CUR);
	}
	fscanf(fp, "%ld'\t'%s'\t'%d", &card_id, passwd, &auth);
	fclose(fp);
	return card_id;
}


long user_add(long card_id, int auth) {
	FILE  *fp;
	long card_id;
	char passwd[MAX_PASSWD];
	fp = fopen("./data/card.txt", "w+");
	printf("添加卡信息");
	fprintf(fp, "%ld%c%s%c%d", card_id, '\t', passwd, '\t', auth);
	fclose(fp);
}



void user_infrmtn(long card_id) {
	FILE  *fp;
	if (fp = fopen("./data/card.txt", "r")) == NULL){
	printf("卡信息不存在");
	return -1;
	}

	int auth;
	char card_id[MAX_ID],passwd[MAX_PASSWD];
	fscanf(fp, "%s'\t'%s'\t'%d", &card_id, passwd, &auth);
	scanf("%ld%s%d", &card_id, passwd, &auth);
}
*/