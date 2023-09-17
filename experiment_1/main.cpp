#define _CRT_SECURE_NO_WARNINGS	1
//
#include "experiment1.h"
void menu()//菜单
{
	cout << "**************************" << endl;
	cout << "******  1.自动测试  ******" << endl;
	cout << "******  2.手动输入  ******" << endl;
	cout << "******  0.退出程序  ******" << endl;
	cout << "**************************" << endl;
}
int main()
{
	srand((unsigned int)time(NULL));//生成随机数种子
	int input = 0;
	double a = 0;
	double b = 0;
	double c = 0;
	do
	{
		menu();//打印菜单
		printf("请选择：>");
		cin >> input;
		switch (input)//对用户输入的结果进行判断
		{
		case 1://结果为1，开始自动测试
			Test1(&a, &b, &c);
			break;
		case 2://结果为2，开始手动输入
			Test2(&a, &b, &c);
			break;
		case 0:
			cout << "退出程序" << endl;
			break;
		default://两个结果都不是，重新输入
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}