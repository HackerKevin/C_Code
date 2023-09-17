#define _CRT_SECURE_NO_WARNINGS	1
#include "experiment1.h"
double GetRoot1(double a, double b, double c, double* ptr)//求根公式法
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
//牛顿迭代法
double OriFun(double x, double a, double b, double c)//原函数
{
	return (a * pow(x, 2) + b * x + c);
}
double DerFun(double x, double a, double b, double c)//导数
{
	return (2 * a * x + b);
}
double newtonIter(double val, double pre, double a, double b, double c) 
{
		//求解
	double res = OriFun(val, a, b, c);
	if (res == 0.0 || fabs(res) < pre)//如果找到
		return val;
	//根据牛顿迭代公式修正 val 值
	if (DerFun(val, a, b, c) == 0)//如果导数为0，调整 vla 值
	{
		val += 0.00001;
		val = val - res / DerFun(val, a, b, c);
	}
	else
	val = val - res / DerFun(val, a, b, c);
	//递归
	return newtonIter(val, pre, a, b, c);
	
}
double GetRoot2(double a, double b, double c)
{
	static int flag = 0;
	double value = 1;//预测值
	double precision = 0.0000001;//精度
	if (flag % 2 == 0)
	{
		flag++;
		return newtonIter(value, precision, a, b, c);
	}
	else
	{
		flag++;
		return (-b / a) - (newtonIter(value, precision, a, b, c));//用韦达定理返回另一个值
	}
}
void GivNum(double** ptr_a, double** ptr_b, double** ptr_c)
{
	//产生0~100范围内的随机数
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
		cout << "本次测试的三个参数为：" << *ptr_a << " " << *ptr_b << " " << *ptr_c << endl;
		double x1 = 0;
		double x2 = 0;
		double delta = (*ptr_b) * (*ptr_b) - 4 * (*ptr_a) * (*ptr_c);
		if (delta < 0)
		{
			cout << "该方程无解！" << endl;
		}
		else if (delta == 0)
		{
			if (fabs(GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1)) == (GetRoot2(*ptr_a, *ptr_b, *ptr_c)))
			{
				cout << "两种方法得到的结果相同，该方程有两个相等的根，其值为：x1 = x2 = " << x1 << endl;
			}
			else
			{
				cout << "两种方法得到的结果不同，该方程有两个相等的根，其值为：x1 = x2 = " << x1 << endl;
				cout << "求根公式法得到的根为：x1 = x2 = " << x1 << endl;
				cout << "牛顿迭代法得到的根为：x1 = x2 = " << (GetRoot2(*ptr_a, *ptr_b, *ptr_c)) << endl;
			}
		}
		else
		{
			x1 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1);
			x2 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x2);
			cout << "求根公式法得到的根为：x1 = " << x1 << " x2 = " << x2 << endl;
			x1 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			x2 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			cout << "牛顿迭代法得到的根为：x1 = " << x1 << " x2 = " << x2 << endl;
		}
		cout << "要继续测试，请输入1" << endl;
		cin >> input;
	} while (input == 1);
	cout << "退出测试" << endl;
}
void Test2(double* ptr_a, double* ptr_b, double* ptr_c)
{
	int input = 0;
	do
	{
		double x1 = 0;
		double x2 = 0;
		cout << "请输入一元二次方程的三个参数：" << endl;
		cin >> *ptr_a >> *ptr_b >> *ptr_c;
		double delta = (*ptr_b) * (*ptr_b) - 4 * (*ptr_a) * (*ptr_c);
		if (delta < 0)
		{
			cout << "该方程无解！" << endl;
		}
		else if (delta == 0)
		{
			if (fabs(GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1)) == (GetRoot2(*ptr_a, *ptr_b, *ptr_c)))
			{
				cout << "两种方法得到的结果相同，该方程有两个相等的根，其值为：x1 = x2 = " << x1 << endl;
			}
			else
			{
				cout << "两种方法得到的结果不同，该方程有两个相等的根，其值为：x1 = x2 = " << x1 << endl;
				cout << "求根公式法得到的根为：x1 = x2 = " << x1 << endl;
				cout << "牛顿迭代法得到的根为：x1 = x2 = " << (GetRoot2(*ptr_a, *ptr_b, *ptr_c)) << endl;
			}
		}
		else
		{
			x1 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x1);
			x2 = GetRoot1(*ptr_a, *ptr_b, *ptr_c, &x2);
			cout << "求根公式法得到的根为：x1 = " << x1 << " x2 = " << x2 << endl;
			x1 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			x2 = GetRoot2(*ptr_a, *ptr_b, *ptr_c);
			cout << "牛顿迭代法得到的根为：x1 = " << x1 << " x2 = " << x2 << endl;
		}
		cout << "要继续测试，请输入1" << endl;
		cin >> input;
	} while (input == 1);
	cout << "退出测试" << endl;
}