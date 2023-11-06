#define _CRT_SECURE_NO_WARNINGS	1
//×Ö·ûÑ¹Ëõ
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	string strzip;
	getline(cin, str);
	int end = str.size() - 1;
	while (end >= 0)
	{
		int count = 1;
		int _end = end - 1;
		
		while (_end >= 0 && str[_end] == str[end])
		{
			count++;
			_end--;
		}
		if (count > 9)
		{
			for (int temp = count; temp > 0;)
			{
				strzip += (temp % 10 + '0');
				temp /= 10;
			}
		}
		else if(count < 9 &&  _end >= -1)
		{
			strzip += (count + '0');
		}
		strzip += str[end];
		end -= count;
	}
	if (str.size() > strzip.size())
	{
		reverse(strzip.begin(), strzip.end());
		cout << strzip << endl;
	}
	else
		cout << str << endl;
	return 0;
}