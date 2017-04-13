#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <tchar.h> 
#include <conio.h> 
#include "menu.h"


void prompt_input(void){
	printf("��������Ӧ�����Խ����Ӧϵͳ:\t\t");
}

void menu_wrong_prompt(void){
	//	system("cls");
	system("color 4F");
	line_breaks(1);
	print_equals(80);
	line_breaks(1);
	puts_center("����");
	line_breaks(1);
	puts_center("δ֪�ش�");
	puts_center("���������������������룡");
	line_breaks(1);
	line_breaks(1);
	print_equals(80);
	_getch();
	fflush(stdin);
	system("cls");
}

void menu_no_permission_prompt(void){
	//	system("cls");
	system("color 4F");
	line_breaks(1);
	print_equals(80);
	line_breaks(1);
	puts_center("����");
	line_breaks(1);
	puts_center("δ֪�ش�");
	puts_center(" ���޴�Ȩ��!");
	line_breaks(1);
	line_breaks(1);
	print_equals(80);
	_getch();
	fflush(stdin);
	system("cls");
}

void puts_center(const char* txt){
	int len, col;
	for (len = (int)strlen(txt); len > 0; len -= col, txt += col){
		col = len < 80 ? len : 80;
		printf("%*.*s\n", 40 + col / 2, col, txt);
	}
}

void print_equals(int num){
	int i = 0;
	for (; i < num; i++)
		printf("=");
}

void line_breaks(int num){
	int i = 0;
	for (; i <= num; i++)
		printf("\n");
}