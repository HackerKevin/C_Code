#include "Assistance.h"

void test_multimap1()
{
	multimap<string, string> mdict;

	mdict.insert(pair<string, string>("sort", "ÅÅĞò"));
	mdict.insert(make_pair("sort", "ÅÅĞò"));
	mdict.insert(make_pair("sort", "ÅÅĞò"));
	mdict.insert(make_pair("string", "×Ö·û´®"));
	mdict.insert(make_pair("count", "¼ÆÊı"));
	mdict.insert(make_pair("string", "(×Ö·û´®)"));

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