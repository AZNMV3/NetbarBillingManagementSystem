#include "../menu.h"
#include "../admin.h"


void purview_man_menu(void) {
	system("cls");
	system("color 2f");
	purview_man_head();
	line_breaks(1);
	purview_man_option();
	line_breaks(2);
	prompt_input();
	menu_purview_man_jump();
}

void purview_man_head(void) {
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	purview_man_content();
	line_breaks(1);
	print_equals(80);
}

void purview_man_content(void) {
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������Ȩ�޹���");
	line_breaks(1);
	puts_center("��Ȩ�޹������������ӡ�ɾ������Ա�����������ǵ�Ȩ�ޡ�");
	puts_center("ע��:ֻ�г�������Ա��Ȩ�������á�");
	line_breaks(1);
}

void purview_man_option(void) {
	printf("��1.���ӹ���Ա��\t��2.ɾ������Ա��\t��3.����Ȩ�ޡ�\t��0.���ء�");
}

void purview_man_add_admin(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);
	char user[MAX_ID];
	char passwd[MAX_PASSWD];
	char temp = 0;
	printf("\n=======���ӹ���Ա======\n");
	printf("������Ҫ���ӵĹ���Ա���û���(12���ַ�����)\n");
	if (!scanf("%s", user)) {
		fflush(stdin);
		printf("\n����Ƿ����˳�");
		return;
	}
	printf("\n������Ҫ���ӵĹ���Ա������\n");
	if (!scanf("%s", passwd)) {
		fflush(stdin);
		printf("\n����Ƿ����˳�");
		return;
	}

	int is_super = 0, allow_cardman = 0, allow_billman = 0, allow_shutman = 0, allow_chargeman = 0, allow_statman = 0;
	printf("\n�Ƿ���Ϊ��������Ա\n");
	if (!scanf("%d", &is_super)) {
		fflush(stdin);
		printf("\n����Ƿ����˳�");
		return;
	}
	if (is_super) {
		allow_cardman = 1, allow_billman = 1, allow_shutman = 1, allow_chargeman = 1, allow_statman = 1;
	}
	else {
		printf("\n�븳�����ԱȨ��\n");
		printf("\n��ʽ:permission \n a\t������Ȩ�� \n b\t�Ʒѱ�׼����Ȩ�� \n m\t���»�����Ȩ�� \n c\t��ֵ�˷�Ȩ�� \n s\t��ѯͳ��Ȩ��\n f\t�������\n");
		printf("\n����:permission --a b m c s f\n");
		printf("\npermission --");

		fflush(stdin);					//�����д������
		while (temp != 'f') {
			scanf("%c", &temp);
			switch (temp) {
			case 'a':allow_cardman = 1; break;
			case 'b':allow_billman = 1; break;
			case 'm':allow_shutman = 1; break;
			case 'c':allow_chargeman = 1; break;
			case 's':allow_statman = 1; break;
			case 'f': break;
				default
					:break;
			}
		}
	}
	admin_add_core(user, passwd, is_super, allow_cardman, allow_billman, allow_shutman, allow_chargeman, allow_statman);
	line_breaks(1);
	system("pause");
	purview_man_menu();
}

void purview_man_del_admin(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);
	char user[MAX_ID];
	//	char su_passwd[MAX_PASSWD];
	char temp = 0;
	printf("\n=======ɾ������Ա======\n");
	printf("������Ҫɾ���Ĺ���Ա���û���\n");
	if (!scanf("%s", user)) {
		fflush(stdin);
		printf("\n����Ƿ����˳�");
		return;
	}
	/*	printf("\n�����볬������Ա����\n");
	if (!scanf("%s", su_passwd)) {
	fflush(stdin);
	printf("\n����Ƿ����˳�");
	*/
	if (admin_has_user(user)) {
		admin_del_core(user);
		printf("\n���û��ѱ�ɾ��\n");
	}
	else {
		printf("���û�������");
	}
	line_breaks(1);
	system("pause");
	purview_man_menu();
}

void purview_man_configure_permissions(void) {
	system("cls");
	print_equals(80);
	line_breaks(1);


	line_breaks(1);
	system("pause");
	purview_man_menu();
}

void menu_purview_man_jump(void) {
	char input = _getch();
	fflush(stdin);
	switch (input) {
	case '0':index_menu();
		break;
	case '1':purview_man_add_admin();
		break;
	case'2':purview_man_del_admin();
		break;
	case'3':purview_man_configure_permissions();
		break;
	default:menu_wrong_prompt(); purview_man_menu();
		break;
	}
}