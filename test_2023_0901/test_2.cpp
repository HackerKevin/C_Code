#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
void swap(double& a, double& b)// 引用型形参不是定义，只是声明，不占空间
{
    double temp;
    temp = a;  					//a, b 绑定对应的实参，是实参的别名。
    a = b;	   					//a,b的生命周期是局部的,函数返回后消失。
    b = temp;  					//再次调用该函数时，可绑定不同的实参。
}


int main()
{
    
    return 0;
}