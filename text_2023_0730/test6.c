#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("��������������������������������������������������������\n");
	printf("����������������������1.play����������������������\n");
	printf("����������������������0.exit����������������������\n");
	printf("��������������������������������������������������������\n");
}

void game()
{
	int count = 7;
	int guess = 0;
	int r = rand() % 100 + 1;
	
	while (count)
	{
		printf("�㻹��%d�λ���\n",count);
		printf("���������֣�>");
		scanf("%d", &guess);
		if (r > guess)
		{
			printf("��С��\n");
		}
		if (r < guess)
		{
			printf("�´���\n");
		}
		if (r == guess)
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("���ź��������ˣ�\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (input);
	return 0;
}