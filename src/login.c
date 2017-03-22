#include "login.h"
#include "card.h"
#include "admin.h"
#include <conio.h>
#include <windows.h>

HANDLE hout;

char* win_getpass(const char* prompt){
	fflush(stdin);
	COORD coord,start;						//��Ļ�ϵ�����
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//����̨��Ļ��������Ϣ
	
	int i,tmp;
	static char buf[MAX_PASSWD+1];
	printf("%s",prompt);				//�����ʾ

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hout, &csbi);
	start.X = csbi.dwCursorPosition.X; 
	start.Y = csbi.dwCursorPosition.Y;

	for(i = 0;i <= MAX_PASSWD;i++){
		tmp=_getch();
		if(tmp == 13){					//13='CR' which means �س�(Carriage Return)
			buf[i] = '\0';
			break;
		}else if(tmp == 8) {
			if(i > 0){
				i--;
				hout = GetStdHandle(STD_OUTPUT_HANDLE);
				GetConsoleScreenBufferInfo(hout, &csbi);
				coord.X = csbi.dwCursorPosition.X; //�õ���������X��ֵ
				coord.Y = csbi.dwCursorPosition.Y;
				if(coord.X-1 >= start.X){
					coord.X--;
					SetConsoleCursorPosition(hout, coord);
				}
				continue;
			}else
				continue;
		}
		buf[i] = tmp;
		putchar(' ');
	}
	putchar('\n');
	return buf;
}

int admin_login(void){
	char username[MAX_ID];
	char *password;
	printf("�������û���:");
	scanf("%s",username);
	password = win_getpass("����������:");
	if (admin_has_user(username))
		if(admin_is_passwd_right(username,password))
			return 1;

	return 0;
}
