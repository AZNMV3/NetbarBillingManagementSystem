#include "login.h"
#include "card.h"
#include "admin.h"
#include <conio.h>

char* win_getpass(const char* prompt){
	fflush(stdin);
	int i,tmp;
	static char buf[MAX_PASSWD+1];
	printf("%s",prompt);				//输出提示
	for(i = 0;i <= MAX_PASSWD;i++){
		tmp=_getch();
		putchar(' ');
		if(tmp == 13){					//13='CR' which means 回车(Carriage Return)
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
	puts("请输入用户名:");
	scanf("%s",username);
	password = win_getpass("请输入密码:");
	if (admin_has_user(username))
		
		if(admin_is_passwd_right(username,password))
			return 1;

	return 0;
}