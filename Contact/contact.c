#define _CRT_SECURE_NO_WARNINGS	1
#include "contact.h"
void InitContact(Contact* pc)
{
	assert(pc);
	memset(pc, 0, sizeof(pc->data));
	pc->sz = 0;
}

	void AddContact(Contact* pc)
	{
		assert(pc);
		if (pc->sz == MAX)
		{
			printf("联系人已满，无法添加\n");
			return;
		}

		printf("请输入姓名：>");
		scanf("%s", pc->data[pc->sz].name);//由于name是数组，数组名在这里又表示首元素地址，所以不用加取地址符号
		printf("请输入年龄：>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别：>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话：>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址：>");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;//录入成功后，联系人个数+1
		printf("成功添加联系人\n");
	}

void ShowContact(const Contact* pc)//由于打印通讯录不需要对其进行修改，因为我们可以加个const进行修饰
{
	assert(pc);
	int i = 0;
	//打印列标题
	printf("%20s\t%4s\t%5s\t%12s\t%30s\n", "姓名", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s\t%4d\t%5s\t%12s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;	
}

void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	char name[MAX_NAME];
	assert(pc);
	//删除
	printf("请输出待删除联系人的姓名：>");
	scanf("%s", name);
	//找到要删除的人
	int i = 0;
	//for (i = 0; i < pc->sz; i++)
	//{
	//	if (strcmp(pc->data[i].name, name) == 0)//不能用pc->data[i].name==name来比较
	//	{
	//		pos = i;
	//		flag = 1;//表示找到了
	//		break;
	//	}
	//}
	//if (flag == 0)
	//{
	//	printf("要删除的人不存在\n");
	//	return;
	//}
	//删除位置在pos的联系人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];//将pos后面的位置整体往前移一位
	}
	pc->sz--;
	printf("成功删除联系人\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("请输入要查找人的名字：>");
	scanf("%s", name);
	pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%20s\t%4s\t%5s\t%12s\t%30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%20s\t%4d\t%5s\t%12s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法修改\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("请输入要修改人的名字：>");
	scanf("%s", name);
	pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入姓名：>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别：>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功\n");
}