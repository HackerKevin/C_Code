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
		//	cout << "��" << endl;
		//}
		//else
		//{
		//	cout << "����" << endl;
		//}
		if (s1.count(x))// ����ڵĻ��᷵�� x �ĸ���
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "����" << endl;
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

	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	// make_pair Ϊһ������ģ��,ʵ���Ͼ��Ƕ� pair<> �ķ�װ
	// ������Ͳ���д�������ͣ��� make_pair �����Զ��Ƶ�
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));

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

	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));
	dict.insert(make_pair("string", "(�ַ���)"));// ����ʧ��

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
	string arr[] = { "����","����","ƻ��" ,"����" ,"ƻ��" ,"ƻ��" ,"����" ,"ƻ��" ,"�㽶" ,"ƻ��" ,"�㽶" ,"��" };

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

	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));

	dict["left"];					// ����
	dict["right"] = "�ұ�";			// ���� + �޸�
	dict["string"] = "�޸�";			// �޸�
	cout << dict["string"] << endl;	// ����

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