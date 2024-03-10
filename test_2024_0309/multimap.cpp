#include "Assistance.h"

void test_multimap1()
{
	multimap<string, string> mdict;

	mdict.insert(pair<string, string>("sort", "����"));
	mdict.insert(make_pair("sort", "����"));
	mdict.insert(make_pair("sort", "����"));
	mdict.insert(make_pair("string", "�ַ���"));
	mdict.insert(make_pair("count", "����"));
	mdict.insert(make_pair("string", "(�ַ���)"));

	for (auto& kv : mdict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

int main()
{
	test_multimap1();
	return 0;
}