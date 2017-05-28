#include "../menu.h"
#include "../card.h"


void card_man_menu(void){
	while (true) {
		system("cls");
		system("color 6f");
		card_man_head();
		line_breaks(1);
		card_man_option();
		line_breaks(2);
		prompt_input();
		menu_card_man_jump();
	}
}

void card_man_head(void){
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	card_man_content();
	line_breaks(2);
	print_equals(80);
}

void card_man_content(void){
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������������");
	line_breaks(1);
	puts_center("�ڿ�����������ִ����ӿ�����ѯ����ɾ����������");
	line_breaks(1);
}

void card_man_option(void){
	printf("\t��1.��ӿ���\t��2.��ѯ����\t��3.ɾ������\t��0.���ء�\t");
}

void card_man_add(void) {
	while(true){
		system("cls");
		print_equals(80);
		line_breaks(1);
		char id[MAX_ID];
		char passwd[MAX_PASSWD];
		double balance = 0;
		puts("\n=======��ӿ�======");
		puts("���������֤�Ż��պ�(������)");
		if (!scanf("%s", id)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		puts("\n�����뿨����");
		if (!scanf("%s", passwd)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}

		puts("\n�����뿪�����");
		if (!scanf("%lf", &balance)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		card_add_core(id, passwd, balance);
		line_breaks(1);
		system("pause");
		return;
	}
}

void card_get_information(void){
	while (true) {
		system("cls");
		print_equals(80);
		line_breaks(1);
		double balance = 0;
		char id[MAX_ID];
		char passwd[MAX_PASSWD];

		puts("������Ҫ��ѯ�Ŀ���");
		if (!scanf("%s", id)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		ULONGLONG start_time = GetTickCount64();
		if (card_has(id))
			balance = card_get_json_value(id, passwd);
		else {
			line_breaks(2);
			printf("���û�������");
			line_breaks(2);
			system("pause");
			card_man_menu();
		}
		system("cls");
		print_equals(80);
		line_breaks(1);
		print_equals(60);
		puts("\n��ѯ���");
		print_equals(60);
		printf("\n����\t\t����\t\t���");
		line_breaks(1);
		print_equals(60);
		line_breaks(1);
		printf("%s\t%s\t\t\t%.2f", id, passwd, balance);
		ULONGLONG stop_time = GetTickCount64();
		line_breaks(2);
		print_equals(80);
		printf("\n��ѯ��ʱ %lldms", stop_time - start_time);
		line_breaks(2);
		system("pause");
		return;
	}
}

void card_man_del(void) {
	while(true){
		system("cls");
		print_equals(80);
		line_breaks(1);
		char id[MAX_ID];
		char temp[MAX_PASSWD];
		puts("\n=======ɾ���˷�======\n");
		printf("������Ҫɾ���Ŀ���:");
		if (!scanf("%s", id)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}

		if (card_has(id)) {
			double balance = card_get_json_value(id, temp);
			card_del_core(id);
			puts("\n���û��ѱ�ɾ��");
			printf("\nӦ�˷�%fԪ\n", balance);
		}
		else {
			printf("���û�������");
		}
		line_breaks(2);
		system("pause");
		return;
	}
}

void menu_card_man_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':card_man_add();
		break;
	case'2':card_get_information();
		break;
	case'3':card_man_del();
		break;
	default:menu_wrong_prompt(); card_man_menu();
		break;
	}
}