#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include "Date.h"
using namespace std;
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
//��������ƫ�ػ�Ϊָ������
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1 _d1;
	T2 _d2;
};
//��������ƫ�ػ�Ϊ��������
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}

private:
	const T1& _d1;
	const T2& _d2;
};
//���ڶ��������ػ�Ϊint
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
void Test2()
{
	Data<double, int> d1;      //�����ػ���int�汾
	Data<int, double> d2;      //���û�����ģ�� 
	Data<int*, int*> d3; 	   //�����ػ���ָ��汾
	Data<int&, int&> d4(1, 2); //�����ػ������ð汾
}
void Test()//ȫ�ػ�
{
	Data<int, int> d1;
	Data<char, int> d2;
}

int main()
{
	Test2();
	return 0;
}

