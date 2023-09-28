#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TALE 20
#define MAX_ADDR 30
enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW
};
//��ϵ�����͵�����
typedef struct PeoInfo
{
	char name[MAX_NAME];
	size_t age;
	char sex[MAX_SEX];
	char tele[MAX_TALE];
	char addr[MAX_ADDR];
}PeoInfo;//���ṹ������struct PeoInfo�ض���ΪPeoInfo

//ͨѶ¼���͵�����
typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;//������¼ͨѶ¼�е���ϵ�˸���
}Contact;//���ṹ������struct Contact�ض���ΪContact

//��ʼ��ͨѶ¼����������
void InitContact(Contact* pc);

//������ϵ�˺���������
void AddContact(Contact* pc);

//��ʾ������ϵ����Ϣ����
void ShowContact(const Contact* pc);

//ɾ����ϵ�˺���������
void DelContact(Contact* pc);

//����ָ����ϵ�˺���������
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ�˺���������
void ModifyContact(Contact* pc);