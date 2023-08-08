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
	//棋盘初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//布置雷
	SetMine(mine, ROW, COL);
	system("cls");//用于清除刚才打印的菜单，使游戏界面美观整洁，调用需要引用头文件<Windows.h>
	//棋盘打印
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL); //用于自己调试观察，比如观察雷是否被正确布置等，确认无误后注释掉即可
	//排查雷
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//打印菜单
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)//对用户输入的结果进行判断
		{
		case 1:
			game();//结果为1，开始游戏
			break;
		case 0://结果为0，退出游戏
			printf("退出游戏\n");
			break;
		default://两个结果都不是，重新输入
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}