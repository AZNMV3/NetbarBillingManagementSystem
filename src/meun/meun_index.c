#include "../menu.h"
#include "../admin.h"

extern unsigned char now_login_admin[MAX_USER_LEN];
extern struct admin now_admin;

void index_menu(void) {
	system("cls");
	system("color 3f");
	index_head();
	line_breaks(1);
	index_option();
	line_breaks(1);
	prompt_input();
	menu_index_jump();
}

void index_head(void) {
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	index_content();
	line_breaks(1);
	print_equals(80);
}

void index_content(void) {
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ");
	line_breaks(1);
	puts_center("��ϵͳ�ɿ������Ʒѱ�׼�������»��������ù���");
	puts_center("��ѯͳ�ƺ�Ȩ�޹���ģ����ɡ�");
	line_breaks(1);
}

void index_option(void) {
	printf("\t��1.������\t��2.�Ʒѱ�׼��\t��3.���»���\t��4.���ù���\t");
	line_breaks(1);
	printf("\t��5.ͳ�Ʋ�ѯ��\t��6.Ȩ�޹���\t\t��0.�ǳ���\t");
}

void menu_index_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':exit(0);
	case 27:exit(0);				//27--ESC
	case '1':if(can_user_enter('a'))
				card_man_menu();
			else
				menu_no_permission_prompt(); index_menu();
		break;
	case'2':if (can_user_enter('b'))
				price_menu();
			else
				menu_no_permission_prompt(); index_menu();
		break;
	case'3':if (can_user_enter('m'))
				on_and_shut_menu();
			else
				menu_no_permission_prompt(); index_menu();
		break;
	case '4':if(can_user_enter('c'))
				balance_man_menu();
			 else
				 menu_no_permission_prompt(); index_menu();
		break;
	case '5':if(can_user_enter('s'))
				statistics_menu();
			 else
				 menu_no_permission_prompt(); index_menu();
		break;
	case '6':if (can_user_enter('z'))
				purview_man_menu();
			 else
				 menu_no_permission_prompt(); index_menu(); 
		break;
	default:menu_wrong_prompt(); index_menu();
		break;
	}
}

bool can_user_enter(char type){
	switch (type) {
	case 'a':if (now_admin.allow_cardman == 1) 
		return true;
			 break;
	case 'b':if (now_admin.allow_billman == 1) 
		return true;
			 break;
	case 'm':if (now_admin.allow_shutman == 1) 
		return true;
			 break;
	case 'c':if (now_admin.allow_chargeman == 1) 
		return true;
			 break;
	case 's':if (now_admin.allow_statman == 1) 
		return true;
			 break;
	default:if (now_admin.is_super == 1) 
		return true;
			break;
	}
	return false;
}