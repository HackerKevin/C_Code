#define _CRT_SECURE_NO_WARNINGS	1
//不创建临时变量（第三个变量），实现两个数的交换。
#include <stdio.h>
void Method1(int *a, int *b)
{
	*a = *a + *b;//a加b的和暂时放在a里面去
	*b = *a - *b;//实际上为a加b减b
	*a = *a - *b;//实际上是a加b减a
	//缺陷：a和b两个数字过大的时候容易导致越界。
}
void Method2(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;//相当于a^b^b，而b^b=0,所以a^b^b=a^0=a
	*a = *a ^ *b;//相当于a^b^a，而由异或运算支持交换律得到a^b^a=a^a^b=b

//这种异或操作具有局限性：
//1.只能作用于整数交换
//2.代码的可读性差
//3.执行的效率低于采用临时变量的方法
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前：a=%d，b=%d\n", a, b);
	Method1(&a, &b);
	printf("第一次交换：a=%d，b=%d\n", a, b);
	Method2(&a, &b);
	printf("第二次交换：a=%d，b=%d\n", a, b);
	return 0;
}