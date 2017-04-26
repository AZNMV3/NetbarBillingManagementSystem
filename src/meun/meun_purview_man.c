#include "../menu.h"
#include "../admin.h"


void purview_man_menu(void){
	while (true){
		system("cls");
		system("color 2f");
		purview_man_head();
		line_breaks(1);
		purview_man_option();
		line_breaks(2);
		prompt_input();
		menu_purview_man_jump();
	}
}

void purview_man_head(void){
	print_equals(80);		//��ӡ��=������ 
	line_breaks(1);
	purview_man_content();
	line_breaks(1);
	print_equals(80);
}

void purview_man_content(void){
	puts_center("��ӭʹ�ñ����ɼƷѹ���ϵͳ��������Ȩ�޹���");
	line_breaks(1);
	puts_center("��Ȩ�޹�����������ӡ�ɾ������Ա�����������ǵ�Ȩ�ޡ�");
	puts_center("ע��:ֻ�г�������Ա��Ȩ�������á�");
	line_breaks(1);
}

void purview_man_option(void){
	printf("\t��1.��ӹ���Ա��\t��2.ɾ������Ա��\t��3.����Ȩ�ޡ�\t��0.���ء�");
}

void purview_man_add_admin(void){
	while(true){
		system("cls");
		print_equals(80);
		line_breaks(1);
		char user[MAX_USER_LEN];
		char passwd[MAX_PASSWD];
		char temp = 0;
		printf("\n=======��ӹ���Ա======\n");
		printf("������Ҫ��ӵĹ���Ա���û���(12���ַ�����)\n");
		if (!scanf("%s", user)){
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		puts("\n������Ҫ��ӵĹ���Ա������(�15λ)");
		if (!scanf("%s", passwd)){
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}

		int is_super = 0, allow_cardman = 0, allow_billman = 0, allow_shutman = 0, allow_chargeman = 0, allow_statman = 0;
		puts("\n�Ƿ���Ϊ��������Ա:");
		puts("0.��ͨ����Ա\n1.��������Ա");
		if (!scanf("%d", &is_super)){
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		if (is_super !=0 && is_super != 1) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		if (is_super){
			allow_cardman = 1, allow_billman = 1, allow_shutman = 1, allow_chargeman = 1, allow_statman = 1;
		}
		else {
			printf("\n�븳�����ԱȨ��\n");
			printf("\n��ʽ:permission \n a\t������Ȩ�� \n b\t�Ʒѱ�׼����Ȩ�� \n m\t���»�����Ȩ�� \n c\t��ֵ�˷�Ȩ�� \n s\t��ѯͳ��Ȩ��\n f\t�������\n");
			printf("\n����:permission --a b m c s f\n");
			printf("\npermission --");

			fflush(stdin);					//�����д������
			while (temp != 'f'){
				scanf("%c", &temp);
				switch (temp){
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
		return;
	}
}

void purview_man_del_admin(void){
	while (true) {
		system("cls");
		print_equals(80);
		line_breaks(1);
		char user[MAX_USER_LEN];
		//	char su_passwd[MAX_PASSWD];
		printf("\n=======ɾ������Ա======\n");
		printf("������Ҫɾ���Ĺ���Ա���û���\n");
		if (!scanf("%s", user)){
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		/*	printf("\n�����볬������Ա����\n");
		if (!scanf("%s", su_passwd)){
		fflush(stdin);
		printf("\n����Ƿ����˳�");
		*/
		if (admin_has_user(user)){
			admin_del_core(user);
			puts("\n���û��ѱ�ɾ��");
		}
		else {
			puts("���û�������");
		}
		line_breaks(1);
		system("pause");
		return;
	}
}

void purview_man_configure_permissions(void) {
	while(true){
		system("cls");
		print_equals(80);
		line_breaks(1);
		char user[MAX_USER_LEN];
		printf("\n=======�޸Ĺ���ԱȨ��======\n");
		puts("������Ҫ�޸�Ȩ�޵Ĺ���Ա���û���");
		if (!scanf("%s", user)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		puts("\n�Ƿ����Ϊ��������Ա");
		int is_super = 0;
		if (!scanf("%d", &is_super)) {
			printf("\n����Ƿ����˳�");
			_getch();
			fflush(stdin);
			continue;
		}
		if (is_super) {
			admin_set_permission(user, 1, 1);
		}
		else {
			puts("\n��ѡ��Ҫ�޸ĵĹ���ԱȨ��");
			puts("\n1.������Ȩ��\n2.�Ʒѱ�׼����Ȩ�� \n3.���»�����Ȩ�� \n 4.��ֵ�˷�Ȩ�� \n 5.��ѯͳ��Ȩ��");
			int value;
			char type;
			scanf("%d", &value);
			switch (value) {
			case 1:type = 'a'; break;
			case 2:type = 'b'; break;
			case 3:type = 'm'; break;
			case 4:type = 'c'; break;
			case 5:type = 's'; break;
			default:type = 0; break;
			}
			fflush(stdin);
			while (true) {
				puts("\n����Ҫ������رո�Ȩ��");
				puts("\n0.�ر�\n1.���� ");
				scanf("%d", &value);
				fflush(stdin);

				if (value == 1 || value == 0) {
					admin_set_permission(user, type, value);
					break;
				}
				puts("\n ����������������������");
			}
		}
		line_breaks(1);
		system("pause");
		return;
	}
}

void menu_purview_man_jump(void){
	char input = _getch();
	fflush(stdin);
	switch (input){
	case '0':index_menu();
		break;
	case ' ':index_menu();
		break;
	case 8:index_menu();			//8--BACKSPACE
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
