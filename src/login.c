#include "login.h"
#include "card.h"
#include "admin.h"
#include <conio.h>

char* win_getpass(const char* prompt){
	fflush(stdin);
	int i,tmp;
	static char buf[MAX_PASSWD+1];
	printf("%s",prompt);				//�����ʾ
	for(i = 0;i <= MAX_PASSWD;i++){
		tmp=_getch();
		putchar(' ');
		if(tmp == 13){					//13='CR' which means �س�(Carriage Return)
			buf[i] = '\0';
			break;
		}
		buf[i] = tmp;
	}
	putchar('\n');
	return buf;
}

int admin_login(void){
	char username[MAX_ID];
	char *password;
	puts("�������û���:");
	scanf("%s",username);
	password = win_getpass("����������:");
	if (admin_has_user(username))
		
		if(admin_is_passwd_right(username,password))
			return 1;

	return 0;
}