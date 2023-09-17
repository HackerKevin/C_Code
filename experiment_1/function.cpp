#define _CRT_SECURE_NO_WARNINGS	1
#include "experiment1.h"
double GetRoot1(double a, double b, double c, double* ptr)//�����ʽ��
{
	static int flag = 0;
	if (flag % 2 == 0)
	{
		*ptr = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		flag++;
		return *ptr;
	}
	else
	{
		*ptr = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		flag++;
		return *ptr;
	}
}
//ţ�ٵ�����
double OriFun(double x, double a, double b, double c)//ԭ����
{
	return (a * pow(x, 2) + b * x + c);
}
double DerFun(double x, double a, double b, double c)//����
{
	return (2 * a * x + b);
}
double newtonIter(double val, double pre, double a, double b, double c) 
{
		//���
	double res = OriFun(val, a, b, c);
	if (res == 0.0 || fabs(res) < pre)//����ҵ�
		return val;
	//����ţ�ٵ�����ʽ���� val ֵ
	if (DerFun(val, a, b, c) == 0)//�������Ϊ0������ vla ֵ
	{
		val += 0.00001;
		val = val - res / DerFun(val, a, b, c);
	}
	else
	val = val - res / DerFun(val, a, b, c);
	//�ݹ�
	return newtonIter(val, pre, a, b, c);
	
}
double GetRoot2(double a, double b, double c)
{
	static int flag = 0;
	double value = 1;//Ԥ��ֵ
	double precision = 0.0000001;//����
	if (flag % 2 == 0)
	{
		flag++;
		return newtonIter(value, precision, a, b, c);
	}
	else
	{
		flag++;
		return (-b / a) - (newtonIter(value, precision, a, b, c));//��Τ�ﶨ������һ��ֵ
	}
}
void GivNum(double** ptr_a, double** ptr_b, double** ptr_c)
{
	//����0~100��Χ�ڵ������
	**ptr_a = (rand() % 100 + 1);
	**ptr_b = (rand() % (100 + 1));
	**ptr_c = (rand() % (100 + 1));
}
void Test1(double* ptr_a, double* ptr_b, double* ptr_c)
{
	int input = 0;
	do 
	{
		GivNum(&ptr_a, &ptr_b, &ptr_c);
		cout << "���β��Ե���������Ϊ��" << *ptr_a << " " << *ptr_b << " " << *ptr_c << endl;
		double x1 = 0;
		double x2 = 0;
		double delta = (*ptr_b) * (*ptr_b) - 4 * (*ptr_a) * (*ptr_c);
		if (delta < 0)
		{
			cout << "�÷����޽⣡" << endl;
		}
		else if (delta == 0)
		{
			if (fabs(GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1)) == (GetRoot2(*ptr_a, *ptr_b, *ptr_c)))
			{
				cout << "���ַ����õ��Ľ����ͬ���÷�����������ȵĸ�����ֵΪ��x1 = x2 = " << x1 << endl;
			}
			else
			{
				cout << "���ַ����õ��Ľ����ͬ���÷�����������ȵĸ�����ֵΪ��x1 = x2 = " << x1 << endl;
				cout << "�����ʽ���õ��ĸ�Ϊ��x1 = x2 = " << x1 << endl;
				cout << "ţ�ٵ������õ��ĸ�Ϊ��x1 = x2 = " << (GetRoot2(*ptr_a, *ptr_b, *ptr_c)) << endl;
			}
		}
		else
		{
			x1 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1);
			x2 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x2);
			cout << "�����ʽ���õ��ĸ�Ϊ��x1 = " << x1 << " x2 = " << x2 << endl;
			x1 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			x2 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			cout << "ţ�ٵ������õ��ĸ�Ϊ��x1 = " << x1 << " x2 = " << x2 << endl;
		}
		cout << "Ҫ�������ԣ�������1" << endl;
		cin >> input;
	} while (input == 1);
	cout << "�˳�����" << endl;
}
void Test2(double* ptr_a, double* ptr_b, double* ptr_c)
{
	int input = 0;
	do
	{
		double x1 = 0;
		double x2 = 0;
		cout << "������һԪ���η��̵�����������" << endl;
		cin >> *ptr_a >> *ptr_b >> *ptr_c;
		double delta = (*ptr_b) * (*ptr_b) - 4 * (*ptr_a) * (*ptr_c);
		if (delta < 0)
		{
			cout << "�÷����޽⣡" << endl;
		}
		else if (delta == 0)
		{
			if (fabs(GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1)) == (GetRoot2(*ptr_a, *ptr_b, *ptr_c)))
			{
				cout << "���ַ����õ��Ľ����ͬ���÷�����������ȵĸ�����ֵΪ��x1 = x2 = " << x1 << endl;
			}
			else
			{
				cout << "���ַ����õ��Ľ����ͬ���÷�����������ȵĸ�����ֵΪ��x1 = x2 = " << x1 << endl;
				cout << "�����ʽ���õ��ĸ�Ϊ��x1 = x2 = " << x1 << endl;
				cout << "ţ�ٵ������õ��ĸ�Ϊ��x1 = x2 = " << (GetRoot2(*ptr_a, *ptr_b, *ptr_c)) << endl;
			}
		}
		else
		{
			x1 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1);
			x2 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x2);
			cout << "�����ʽ���õ��ĸ�Ϊ��x1 = " << x1 << " x2 = " << x2 << endl;
			x1 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			x2 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			cout << "ţ�ٵ������õ��ĸ�Ϊ��x1 = " << x1 << " x2 = " << x2 << endl;
		}
		cout << "Ҫ�������ԣ�������1" << endl;
		cin >> input;
	} while (input == 1);
	cout << "�˳�����" << endl;
}