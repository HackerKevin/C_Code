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
	printf("----- 扫雷游戏 -----\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);//打印行号
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印列号
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----- 扫雷游戏 -----\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//随机确认布置雷的坐标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')//是字符'0'说明这个位置没有被布置过
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
		mine[x + 1][y + 1] - 8 * '0');//字符数字减去字符0得到对应的数值数字
	//由于该函数是专门用于函数FindMine的，只在game.c内运行，
	//所以不需要在game.h中声明
}

void MarkMine(char board[ROWS][COLS], int row, int col,int x,int y)
{
	
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断输入的坐标是否在排查范围内
		{
			if (board[x][y] == '*')//标记
			{
				board[x][y] = '!';
				break;
			}
			if (board[x][y] == '!')//取消标记
			{
				board[x][y] = '*';
				break;
			}
			else
			{
				printf("\n输入错误，请输入未被排查的坐标！\n");
				continue;
			}
		}
		else
		{
			printf("输入错误，请输入正确的坐标！\n");
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
		printf("请输入要排查的坐标(如要标记雷，请在坐标前输入\"!\"：>");
		while ((ch = getchar()) != '\n');//输入数字后回车，这个回车会留在待读取的区域，需要用getchar吸收
		
		if (scanf("%d %d", &x, &y) == 2)//排查雷
		{
			if (x >= 1 && x <= row && y >= 1 && y <= col)//判断输入的坐标是否在排查范围内
			{
				if (show[x][y] != '*')//判断输入的坐标是否已经被排查过
				{
					printf("该坐标被排查过，重新输入坐标\n");
					continue;
				}
				else if (mine[x][y] == '1')
				{
					system("cls");
					printf("很遗憾，你被炸死了\n");
					lose = 1;
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					ExplosionSpread(mine, show, row, col, x, y, pw);
					//int count = GetMineCount(mine, x, y);//统计坐标周围有几个雷
					//show[x][y] = count + '0';//数字加上字符0可以得到对应数字的字符
					system("cls");
					DisplayBoard(show, ROW, COL);
				}
			}
			else
			{
				printf("坐标非法，重新输入\n");
			}
			if (win == row * col - EASY_COUNT)
			{
				system("cls");
				printf("恭喜你，排雷成功\n");
				DisplayBoard(mine, ROW, COL);
			}
		}
		else if (scanf("%c %d %d", &ch, &x, &y) == 3)//标记雷
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
	if (x >= 1 && x <= row && y >= 1 && y <= col) //判断输入的坐标是否在排查范围内,否则递归的坐标可能出到棋盘外
	{
		int count = GetMineCount(mine, x, y);//统计坐标周围有几个雷
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