#define _CRT_SECURE_NO_WARNINGS	1
//new���
#include <iostream>
using namespace std;
int main()
{
	int* p1 = new int;//����1��int������ʼ��
	int* p2 = new int(10);//����1��int����ʼ��Ϊ10
	int* p3 = new int[10];//����1����10��int�����飬����ʼ��
	int* p4 = new	int[10]{ 1,2,3,4 };////����1����10��int�����飬ǰ4��Ԫ�س�ʼ��Ϊ1��2��3��4

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}