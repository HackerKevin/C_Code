#define _CRT_SECURE_NO_WARNINGS	1
//Ä£°åÀí½â2
#include <iostream>
using namespace std;
template<typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}
int main()
{
	int i1 = 10;
	int i2 = 20;
	Swap(i1, i2);
	double d1 = 10.0;
	double d2 = 20.0;
	Swap(d1, d2);
	char a = '0';
	char b = '9';
	Swap(a, b);
	return 0;
}