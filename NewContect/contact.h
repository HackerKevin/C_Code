#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TALE 20
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define EXP_SZ 2
enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW
};
//联系人类型的声明
typedef struct PeoInfo
{
	char name[MAX_NAME];
	size_t age;
	char sex[MAX_SEX];
	char tele[MAX_TALE];
	char addr[MAX_ADDR];
}PeoInfo;//将结构体类型struct PeoInfo重定义为PeoInfo

//通讯录类型的声明
typedef struct Contact
{
	PeoInfo* data;//指向存放数据的空间
	int sz;//用来记录通讯录中的联系人个数
	int capacity;//记录当前通讯录的最大容量
}Contact;//将结构体类型struct Contact重定义为Contact

//初始化通讯录函数的声明
void InitContact(Contact* pc);

//增加联系人函数的声明
void AddContact(Contact* pc);

//显示所有联系人信息函数
void ShowContact(const Contact* pc);

//删除联系人函数的声明
void DelContact(Contact* pc);

//查找指定联系人函数的声明
void SearchContact(const Contact* pc);

//修改指定联系人函数的声明
void ModifyContact(Contact* pc);

//释放通讯录空间函数的声明
void FreeContact(Contact* pc);