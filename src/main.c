#include "menu.h"
#include "login.h"

void statistics_print_out_an_user(char id[]);
extern struct admin now_admin;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
//	while(true){
		system("chcp 936");
		system("cls");
		if (admin_login()){
			puts("Login successful!");
			index_menu();
		}else{
			puts("We can't let you log in. Please check your username and password.");
			system("pause");
		}
//	}
	return 0;
}
