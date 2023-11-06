#define _CRT_SECURE_NO_WARNINGS	1
//模板的特化理解
#include <iostream>
#include "Date.h"
using namespace std;
template<class T>
bool Less(T left, T right)
{
	return left < right;
}
//模板的特化
template<>
bool Less<Date*>(Date* left, Date* right)
{
	return *left < *right;
}
int main()
{
	cout << Less(1, 2) << endl;
	Date d1(2022, 7, 7);
	Date d2(2022, 7, 8);
	cout << Less(d1, d2) << endl; 
	Date* p1 = &d1;
	Date* p2 = &d2;
	cout << Less(p1, p2) << endl; 
	return 0;
}

