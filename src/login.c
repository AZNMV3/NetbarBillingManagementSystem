#include "login.h"
#include "admin.h"
#include "menu.h"
#include <io.h>
#include <direct.h>

unsigned char now_login_admin[MAX_USER_LEN];
struct admin now_admin;
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
		}else if(tmp == 8){
			if (i > 0)
				i -= 2;
			if (i == 0)
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
		}else if (tmp == 27)
			exit(0);
		buf[i] = tmp;
		putchar(' ');
	}
	buf[i] = '\0';
	puts(buf);
	putchar('\n');
	return buf;
}

bool admin_login(void){
	system("color 2E");
	unsigned char username[MAX_USER_LEN];
	char *password;
	puts("\n\n\n\n\n");
	printf("\t\t\t\t\t");
	printf("�����û�:");
	scanf("%s",username);
	printf("\n");
	password = win_getpass("\t\t\t\t\t�˻�����:");
	if (admin_has_user(username))
		if(admin_is_passwd_right(username,password)){
			strcpy(now_login_admin, username);
			now_login_admin_permissions(now_login_admin);
			return true;
		}
	return false;
}

void now_login_admin_permissions(char user[]){
	now_admin=write_permissions(user);
}

bool is_admin_file_exist(void){
	signed int result= _access(FILE_POSITION, 0);
	if(result == 0)
		return true;
	if (_access(DATA_DIR, 0) != 0)
			_mkdir("data");
	return false;
}
