#define _CRT_SECURE_NO_WARNINGS	1
//
#include "experiment1.h"
void menu()//�˵�
{
	cout << "**************************" << endl;
	cout << "******  1.�Զ�����  ******" << endl;
	cout << "******  2.�ֶ�����  ******" << endl;
	cout << "******  0.�˳�����  ******" << endl;
	cout << "**************************" << endl;
}
int main()
{
	srand((unsigned int)time(NULL));//�������������
	int input = 0;
	double a = 0;
	double b = 0;
	double c = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��>");
		cin >> input;
		switch (input)//���û�����Ľ�������ж�
		{
		case 1://���Ϊ1����ʼ�Զ�����
			Test1(&a, &b, &c);
			break;
		case 2://���Ϊ2����ʼ�ֶ�����
			Test2(&a, &b, &c);
			break;
		case 0:
			cout << "�˳�����" << endl;
			break;
		default://������������ǣ���������
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}