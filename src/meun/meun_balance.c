#include "../menu.h"
#include "../card.h"


void balance_man_menu(void){
	while (true){
	system("cls");
	system("color 5f");
	balance_man_head();
	line_breaks(1);
	balance_man_option();
	line_breaks(2);
	prompt_input();
	menu_balance_jump();
	}
}

void balance_man_head(void){
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	balance_man_content();
	line_breaks(1);
	print_equals(80);
}

void balance_man_content(void){
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������������");
	line_breaks(1);
	puts_center("�ڷ��ù��������Ը�һ���Ѿ����ڵĿ����г�ֵ�򽫿������ظ��û���");
	line_breaks(2);
}

void balance_man_option(void){
	printf("\t��1.��ֵ��\t��2.�˷ѡ�\t��0.���ء�\t");
}


void balance_man_top_up(void){
	char id[MAX_ID];
	float money = 0;
	puts("\n=======��ֵ======");
	puts("������Ҫ��ֵ�Ŀ���");
	if (!scanf("%s", id)){
		puts("\n����Ƿ����˳�");
		_getch();
		fflush(stdin);
		return;
	}
	puts("������Ҫ��ֵ�Ľ��:");
	if (!scanf("%f", &money)){
		puts("\n����Ƿ����˳�");
		_getch();
		fflush(stdin);
		return;
	}
	ULONGLONG start_time = GetTickCount64();

	if (card_has(id)){
	top_up(id,money);
	char temp[MAX_PASSWD];
	float balance = card_get_json_value(id, temp);
	printf("���ѳɹ���ֵ%.2fԪ���������Ϊ%.2f\n", money, balance);
	}else {
		printf("���û�������");
	}
	ULONGLONG stop_time = GetTickCount64();
	printf("\n��ʱ %lldms", stop_time - start_time);
	line_breaks(2);
	system("pause");
	return;
}


void balance_man_withdraw(void){
	print_equals(80);
	line_breaks(1);
	char id[MAX_ID];
	char temp[MAX_PASSWD];
	printf("\n=======�˷�======\n");
	puts("������Ҫ�˷ѵĿ���");
	if (!scanf("%s", id)){
		puts("\n����Ƿ����˳�");
		_getch();
		fflush(stdin);
		return;
	}

	if (card_has(id)){
		float balance = card_get_json_value(id, temp);
		printf("\nӦ�˷�%fԪ����ע��ֻ����ȫ���˷�\n", balance);
		cost(id, balance);
		printf("���ѳɹ��˷ѣ�");
	}
	else {
		printf("���û�������");
	}
	line_breaks(2);
	system("pause");
	return;
}

void menu_balance_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
		break;
	case '1':balance_man_top_up();
		break;
	case'2':balance_man_withdraw();
		break;
	default:menu_wrong_prompt(); balance_man_menu();
		break;
	}
}
