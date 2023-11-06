#define _CRT_SECURE_NO_WARNINGS	1
//415. 字符串相加
#include <iostream>
#include <string>
using namespace std;
//string addStrings(string num1, string num2) 
//{
//	int end1 = num1.size() - 1;
//	int end2 = num2.size() - 1;
//	int next = 0;
//	string strret;
//	while (end1 >= 0 || end2 >= 0)
//	{
//		/*int val1 = 0;
//		if (end1 >= 0)
//			val1 = num1[end1] - '0';
//		int val2 = 0;
//		if (end2 >= 0)
//			val2 = num2[end2] - '0';*/
//		int val1 = end1 >= 0 ? num1[end1] - '0' : 0;//如果第一个字符串已经遍历完了，就不需要赋值直接置零，所以需要判断
//		int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//		int ret = val1 + val2 + next;
//		/*if (ret > 9)
//		{
//			ret -= 10;
//			next = 1;
//		}
//		else
//		{
//			next = 0;
//		}*/
//		next = ret / 10;
//		ret = ret % 10;
//		strret.insert(0, 1, '0' + ret);
//		--end1;
//		--end2;
//	}
//	if (next == 1)
//		strret.insert(0, 1, '1');
//		/*strret += '1';
//	reverse(strret.begin(), strret.end());*/
//	return strret;
//}
string addStrings(string num1, string num2)
{
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	int next = 0;
	string strret;
	strret.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
	while (end1 >= 0 || end2 >= 0)
	{
		int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
		int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
		int ret = val1 + val2 + next;

		next = ret / 10;
		ret = ret % 10;
		strret += ('0' + ret);
		--end1;
		--end2;
	}
	if (next == 1)
		strret += '1';
	reverse(strret.begin(), strret.end());
	return strret;
}