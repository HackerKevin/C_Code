#define _CRT_SECURE_NO_WARNINGS	1
#include "game.h"

void menu()
{
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.exit  ******\n");
	printf("**********************\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//���̳�ʼ��
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//������
	SetMine(mine, ROW, COL);
	system("cls");//��������ղŴ�ӡ�Ĳ˵���ʹ��Ϸ�����������࣬������Ҫ����ͷ�ļ�<Windows.h>
	//���̴�ӡ
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL); //�����Լ����Թ۲죬����۲����Ƿ���ȷ���õȣ�ȷ�������ע�͵�����
	//�Ų���
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)//���û�����Ľ�������ж�
		{
		case 1:
			game();//���Ϊ1����ʼ��Ϸ
			break;
		case 0://���Ϊ0���˳���Ϸ
			printf("�˳���Ϸ\n");
			break;
		default://������������ǣ���������
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}