#include "menu.h"
#include "login.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("cls");
	if (admin_login()){
		puts("Login successful!");
		index_menu();
	}else{
		puts("We can't let you log in. Please check your username and password.");
		system("pause");
	}
	return 0;
}