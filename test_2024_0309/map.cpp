#include "Assistance.h"

#include "Assistance.h"
#include <set>
#include <map>

void test_set1()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{

		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	int x;
	while (cin >> x)
	{
		//auto ret = s1.find(x);
		//if (ret != s1.end())
		//{
		//	cout << "在" << endl;
		//}
		//else
		//{
		//	cout << "不在" << endl;
		//}
		if (s1.count(x))// 如果在的话会返回 x 的个数
		{
			cout << "在" << endl;
		}
		else
		{
			cout << "不在" << endl;
		}
	}
}

void test_set3()
{
	multiset<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	s1.insert(2);

	/*multiset<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{

		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	auto ret = s1.find(1);
	while (ret != s1.end() && *ret == 1)
	{
		cout << *ret << " ";
		++ret;
	}
	cout << endl;*/

	cout << s1.count(1) << endl;
	cout << s1.count(2) << endl;
}

void test_map1()
{
	map<string, string> dict;

	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(make_pair("sort", "排序"));
	// make_pair 为一个函数模板,实际上就是对 pair<> 的封装
	// 用这个就不用写参数类型，而 make_pair 可以自动推导
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("count", "计数"));

	// map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		// cout << (*dit).first << " ";
		cout << dit->first << " ";
		++dit;
	}
	cout << endl;
}

void test_map2()
{
	map<string, string> dict;

	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("count", "计数"));
	dict.insert(make_pair("string", "(字符串)"));// 插入失败

	// map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << " ";
		++dit;
	}
	cout << endl;
}

void test_map3()
{
	string arr[] = { "西瓜","西瓜","苹果" ,"西瓜" ,"苹果" ,"苹果" ,"西瓜" ,"苹果" ,"香蕉" ,"苹果" ,"香蕉" ,"梨" };

	map<string, int> countMap;

	/*for (auto& e : arr)
	{
		auto ret = countMap.find(e);
		if (ret == countMap.end())
		{
			countMap.insert(make_pair(e, 1));
		}
		else
		{
			ret->second++;
		}
	}*/

	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map4()
{
	map<string, string> dict;

	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));

	dict["left"];					// 插入
	dict["right"] = "右边";			// 插入 + 修改
	dict["string"] = "修改";			// 修改
	cout << dict["string"] << endl;	// 查找

	auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << " ";
		++dit;
	}
	cout << endl;
}
//V& operator[](const K& key)
//{
//	pair<iterator, bool> ret = insert(make_pair(key, V()));
//	return ret.first->second;
//}

int main()
{
	test_map4();
	return 0;
}