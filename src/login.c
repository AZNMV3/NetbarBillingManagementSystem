#include "login.h"
#include "admin.h"

unsigned char now_login_admin[MAX_USER_LEN];
struct admin now_admin;
HANDLE hout;

char* win_getpass(const char* prompt){
	fflush(stdin);
	COORD coord,start;						//屏幕上的坐标
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//控制台屏幕缓冲区信息
	
	int i,tmp;
	static char buf[MAX_PASSWD+1];
	printf("%s",prompt);				//输出提示

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hout, &csbi);
	start.X = csbi.dwCursorPosition.X; 
	start.Y = csbi.dwCursorPosition.Y;
	
	for(i = 0;i <= MAX_PASSWD;i++){
		tmp=_getch();
		if(tmp == 13){					//13='CR' which means 回车(Carriage Return)
			buf[i] = '\0';
			break;
		}
		if(tmp == 8) {
			if (i > 0)
				i -= 2;
			if (i == 0)
				i--;
			hout = GetStdHandle(STD_OUTPUT_HANDLE);
			GetConsoleScreenBufferInfo(hout, &csbi);
			coord.X = csbi.dwCursorPosition.X; //得到现在坐标X的值
			coord.Y = csbi.dwCursorPosition.Y;
			if(coord.X-1 >= start.X){
				coord.X--;
				SetConsoleCursorPosition(hout, coord);
			}
		continue;
		}
		buf[i] = tmp;
		putchar(' ');
	}
	puts(buf);
	putchar('\n');
	return buf;
}

int admin_login(void){
	system("color 2E");
	unsigned char username[MAX_USER_LEN];
	char *password;
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t");
	printf("管理用户:");
	scanf("%s",username);
	printf("\n");
	password = win_getpass("\t\t\t\t\t账户密码:");
	if (admin_has_user(username))
		if(admin_is_passwd_right(username,password)){
			strcpy(now_login_admin, username);
			now_login_admin_permissions(now_login_admin);
			return 1;
		}
	return 0;
}

void now_login_admin_permissions(char user[]) {
	now_admin=write_permissions(user);
}
