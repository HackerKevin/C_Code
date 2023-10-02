#define _CRT_SECURE_NO_WARNINGS	1
//缺省参数的分类
#include <iostream>
using namespace std;
struct Stack
{
	int* a;
	int top;
	int capacity;
};
void StackInit(struct Stack* ps, int defaultCapicity = 4)
{
	ps->a = (int*)malloc(sizeof(int) * defaultCapicity);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = defaultCapicity;
}
void Func1(int a = 10, int b = 20, int c = 30)//全缺省参数
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
void Func2(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	Func2(1, 2, 3);
	Func2(1,2);
	Func2(1);
	return 0;
}
