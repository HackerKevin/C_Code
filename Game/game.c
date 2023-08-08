#define _CRT_SECURE_NO_WARNINGS	1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("----- ɨ����Ϸ -----\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----- ɨ����Ϸ -----\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//���ȷ�ϲ����׵�����
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')//���ַ�'0'˵�����λ��û�б����ù�
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0');//�ַ����ּ�ȥ�ַ�0�õ���Ӧ����ֵ����
	//���ڸú�����ר�����ں���FindMine�ģ�ֻ��game.c�����У�
	//���Բ���Ҫ��game.h������
}

void MarkMine(char board[ROWS][COLS], int row, int col,int x,int y)
{
	
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����������Ƿ����Ų鷶Χ��
		{
			if (board[x][y] == '*')//���
			{
				board[x][y] = '!';
				break;
			}
			if (board[x][y] == '!')//ȡ�����
			{
				board[x][y] = '*';
				break;
			}
			else
			{
				printf("\n�������������δ���Ų�����꣡\n");
				continue;
			}
		}
		else
		{
			printf("���������������ȷ�����꣡\n");
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int* pw = &win;
	char ch = 0;
	int lose = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������(��Ҫ����ף���������ǰ����\"!\"��>");
		while ((ch = getchar()) != '\n');//�������ֺ�س�������س������ڴ���ȡ��������Ҫ��getchar����
		
		if (scanf("%d %d", &x, &y) == 2)//�Ų���
		{
			if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����������Ƿ����Ų鷶Χ��
			{
				if (show[x][y] != '*')//�ж�����������Ƿ��Ѿ����Ų��
				{
					printf("�����걻�Ų����������������\n");
					continue;
				}
				else if (mine[x][y] == '1')
				{
					system("cls");
					printf("���ź����㱻ը����\n");
					lose = 1;
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					ExplosionSpread(mine, show, row, col, x, y, pw);
					//int count = GetMineCount(mine, x, y);//ͳ��������Χ�м�����
					//show[x][y] = count + '0';//���ּ����ַ�0���Եõ���Ӧ���ֵ��ַ�
					system("cls");
					DisplayBoard(show, ROW, COL);
				}
			}
			else
			{
				printf("����Ƿ�����������\n");
			}
			if (win == row * col - EASY_COUNT)
			{
				system("cls");
				printf("��ϲ�㣬���׳ɹ�\n");
				DisplayBoard(mine, ROW, COL);
			}
		}
		else if (scanf("%c %d %d", &ch, &x, &y) == 3)//�����
		{
			MarkMine(show, row, col, x, y);
			system("cls");
			DisplayBoard(show, ROW, COL);
			continue;
		}
	}
}


void ExplosionSpread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* pw)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col) //�ж�����������Ƿ����Ų鷶Χ��,����ݹ��������ܳ���������
	{
		int count = GetMineCount(mine, x, y);//ͳ��������Χ�м�����
		if (count == 0)
		{
			show[x][y] = ' ';
			(*pw)++;
			int i = 0;
			int j = 0;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')
						ExplosionSpread(mine, show, row, col, i, j, pw);
				}
			}
		}
		else
		{
			show[x][y] = count + '0';
			(*pw)++;
		}
	}
}