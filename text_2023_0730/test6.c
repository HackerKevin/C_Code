#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("————————————————————————————\n");
	printf("———————————1.play———————————\n");
	printf("———————————0.exit———————————\n");
	printf("————————————————————————————\n");
}

void game()
{
	int count = 7;
	int guess = 0;
	int r = rand() % 100 + 1;
	
	while (count)
	{
		printf("你还有%d次机会\n",count);
		printf("请输入数字：>");
		scanf("%d", &guess);
		if (r > guess)
		{
			printf("猜小了\n");
		}
		if (r < guess)
		{
			printf("猜大了\n");
		}
		if (r == guess)
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("很遗憾，你输了！\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);
	return 0;
}