#include "menu.h"
#include "login.h"
#include "price.h"

extern struct admin now_admin;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[])
{
	if (!is_admin_file_exist())
		purview_man_add_admin();
	if (!is_price_file_exist())
		price_add_a_billing_standards();
	while (true) {
		system("chcp 936");
		system("cls");
		if (admin_login()) {
			puts("Login successful!");
			index_menu();
		}
		else {
			puts("We can't let you log in. Please check your username and password.");
			system("pause");
		}
	}
	return 0;
}
