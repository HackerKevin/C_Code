#define _CRT_SECURE_NO_WARNINGS	1
//�ڴ�й©���
#include <iostream>
using namespace std;
void MemoryLeaks()
{
	// 1.�ڴ������������ͷ�
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;

	// 2.�쳣��ȫ����
	int* p3 = new int[10];

	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.

	delete[] p3;
}
