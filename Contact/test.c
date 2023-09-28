#define _CRT_SECURE_NO_WARNINGS	1
#include "contact.h"
void menu()
{
	printf("***********************\n");
	printf("******  1.add    ******\n");
	printf("******  2.del    ******\n");
	printf("******  3.search ******\n");
	printf("******  4.modify ******\n");
	printf("******  5.show   ******\n");
	printf("******  0.exit   ******\n");
	printf("***********************\n");
}

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();//打印菜单
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)//对用户输入的结果进行判断
		{
		case ADD://结果为1，增加联系人
			AddContact(&con);
			break;
		case DEL://结果为2，删除联系人
			DelContact(&con);
			break;
		case SEARCH://结果为3，查找指定联系人
			SearchContact(&con);
			break;
		case MODIFY://结果为4，修改联系人信息
			ModifyContact(&con);
			break;
		case SHOW://结果为5，显示所有联系人信息
			ShowContact(&con);
			break;
		case EXIT://结果为0，退出通讯录
			printf("退出通讯录\n");
			break;
		default://所有结果都不是，重新输入
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}