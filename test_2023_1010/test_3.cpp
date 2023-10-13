#define _CRT_SECURE_NO_WARNINGS	1
//new和malloc的区别（1）
#include <iostream>
using namespace std;
int main()
{
	int* p1 = (int*)malloc(sizeof(int)); 
	int* p2 = new int;
	*p1 = 1;
	*p2 = 1;
	cout << "p1:" << *p1 << endl;
	cout << "p2:" << *p2 << endl;
	free(p1);
	delete p2;
}