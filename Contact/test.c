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
		menu();//��ӡ�˵�
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)//���û�����Ľ�������ж�
		{
		case ADD://���Ϊ1��������ϵ��
			AddContact(&con);
			break;
		case DEL://���Ϊ2��ɾ����ϵ��
			DelContact(&con);
			break;
		case SEARCH://���Ϊ3������ָ����ϵ��
			SearchContact(&con);
			break;
		case MODIFY://���Ϊ4���޸���ϵ����Ϣ
			ModifyContact(&con);
			break;
		case SHOW://���Ϊ5����ʾ������ϵ����Ϣ
			ShowContact(&con);
			break;
		case EXIT://���Ϊ0���˳�ͨѶ¼
			printf("�˳�ͨѶ¼\n");
			break;
		default://���н�������ǣ���������
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}