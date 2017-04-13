#include "../menu.h"
#include "../price.h"
#include "../card.h"
#include "../login.h"


void on_and_shut_menu(void){
	while (true){
		system("cls");
		system("color 1f");
		on_and_shut_head();
		line_breaks(1);
		on_and_shut_option();
		line_breaks(2);
		prompt_input();
		menu_on_and_shut_jump();
	}
}

void on_and_shut_head(void){
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	on_and_shut_content();
	line_breaks(1);
	print_equals(80);
}

void on_and_shut_content(void){
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ�����������»�");
	line_breaks(1);
	puts_center("�ڼƷѹ������������뿨���ϻ�������»����㡣");
	line_breaks(2);
}

void on_and_shut_option(void){
	printf("\t��1.�ϻ���\t��2.�»���\t��0.���ء�\t");
}


void on_and_shut_power_on(void){
	char id[MAX_ID];
	char *passwd;
	//	char str[25];
	printf("\n�����뿨��\n");
	scanf("%s", id);
	passwd = win_getpass("\n����������\n");
	if(!card_has(id)){
		printf("���Ż��������");
	}else{
		if (can_card_login(id, passwd))
			write_login(time_sec(), id);
		else
		printf("���Ż��������");
	}
	system("pause");
	return;
}

void on_and_shut_power_off(void){
	char id[MAX_ID];
	char temp[MAX_PASSWD];
	printf("\n�����뿨��\n");
	scanf("%s", id);
	if(card_has(id)){
		shut_core(id);
		printf("\n�»��ɹ���?���Ŀ����Ϊ%.2f", card_get_json_value(id,temp));
	}else {
		puts("�˺Ų����ڣ��������룡");
	}
	system("pause");
	return;
}

void menu_on_and_shut_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':on_and_shut_power_on();
		break;
	case'2':on_and_shut_power_off();
		break;
	default:menu_wrong_prompt(); on_and_shut_menu();
		break;
	}
}
