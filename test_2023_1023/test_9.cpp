#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int a[128] = { 0 };
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		a[str[i]]++;
	}
	for (int j = 127; j >= 0; j--)
	{
		if (a[j] > 0)
		{
			printf("%c", j);
			a[j] = 0;
		}
	}
	return 0;
}