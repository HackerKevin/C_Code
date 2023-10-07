#define _CRT_SECURE_NO_WARNINGS	1
//计算日期到天数转换
#include <iostream>
using namespace std;
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	int monthDay1_N[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	int nday = monthDay1_N[month - 1];
	nday += day;
	if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		nday += 1;
	}
	cout << nday << endl;
}