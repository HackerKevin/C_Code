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
			printf("��ϵ���������޷����\n");
			return;
		}

		printf("������������>");
		scanf("%s", pc->data[pc->sz].name);//����name�����飬�������������ֱ�ʾ��Ԫ�ص�ַ�����Բ��ü�ȡ��ַ����
		printf("���������䣺>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�������Ա�>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("������绰��>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("�������ַ��>");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;//¼��ɹ�����ϵ�˸���+1
		printf("�ɹ������ϵ��\n");
	}

void ShowContact(const Contact* pc)//���ڴ�ӡͨѶ¼����Ҫ��������޸ģ���Ϊ���ǿ��ԼӸ�const��������
{
	assert(pc);
	int i = 0;
	//��ӡ�б���
	printf("%20s\t%4s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
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
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	char name[MAX_NAME];
	assert(pc);
	//ɾ��
	printf("�������ɾ����ϵ�˵�������>");
	scanf("%s", name);
	//�ҵ�Ҫɾ������
	int i = 0;
	//for (i = 0; i < pc->sz; i++)
	//{
	//	if (strcmp(pc->data[i].name, name) == 0)//������pc->data[i].name==name���Ƚ�
	//	{
	//		pos = i;
	//		flag = 1;//��ʾ�ҵ���
	//		break;
	//	}
	//}
	//if (flag == 0)
	//{
	//	printf("Ҫɾ�����˲�����\n");
	//	return;
	//}
	//ɾ��λ����pos����ϵ��
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];//��pos�����λ��������ǰ��һλ
	}
	pc->sz--;
	printf("�ɹ�ɾ����ϵ��\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%20s\t%4s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ��޷��޸�\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("������������>");
	scanf("%s", pc->data[pos].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pos].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pos].addr);

	printf("�޸ĳɹ�\n");
}