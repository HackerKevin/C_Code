#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

double GetRoot1(double a, double b, double c, double* ptr);//求根公式法
double GetRoot2(double a, double b, double c);//牛顿迭代法
double OriFun(double x, double a, double b, double c);//原函数
double DerFun(double x, double a, double b, double c);//导函数
void GivNum(double** ptr_a, double** ptr_b, double** ptr_c);//随机赋值
void Test1(double* ptr_a, double* ptr_b, double* ptr_c);//自动输入
void Test2(double* ptr_a, double* ptr_b, double* ptr_c);//手动输入