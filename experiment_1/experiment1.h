#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

double GetRoot1(double a, double b, double c, double* ptr);//�����ʽ��
double GetRoot2(double a, double b, double c);//ţ�ٵ�����
double OriFun(double x, double a, double b, double c);//ԭ����
double DerFun(double x, double a, double b, double c);//������
void GivNum(double** ptr_a, double** ptr_b, double** ptr_c);//�����ֵ
void Test1(double* ptr_a, double* ptr_b, double* ptr_c);//�Զ�����
void Test2(double* ptr_a, double* ptr_b, double* ptr_c);//�ֶ�����