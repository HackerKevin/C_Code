#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
void swap(double& a, double& b)// �������ββ��Ƕ��壬ֻ����������ռ�ռ�
{
    double temp;
    temp = a;  					//a, b �󶨶�Ӧ��ʵ�Σ���ʵ�εı�����
    a = b;	   					//a,b�����������Ǿֲ���,�������غ���ʧ��
    b = temp;  					//�ٴε��øú���ʱ���ɰ󶨲�ͬ��ʵ�Ρ�
}


int main()
{
    
    return 0;
}