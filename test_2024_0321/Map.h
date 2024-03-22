#pragma once
#include "RBTree.h"
namespace Kevin
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
		}

		pair<iterator,bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t; //可以修改second，但不能修改key

	};

	void Test_Map()
	{
		map<string, string> m;
		m.insert(make_pair("sort", "排序"));
		m.insert(make_pair("string", "字符串"));
		m.insert(make_pair("count", "计数"));

		map<string, string>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto& e : m)
		{
			cout << e.first << ": " << e.second << endl;
		}
		cout << endl;
	}

	void Test_Map2()
	{
		string arr[] = { "西瓜","西瓜","苹果" ,"西瓜" ,"苹果" ,"苹果" ,"西瓜" ,"苹果" ,"香蕉" ,"苹果","香蕉","梨" };
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
	
}

