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

		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;

	};

	void Test_Map()
	{
		map<string, string> m;
		m.insert(make_pair("sort", "ÅÅÐò"));
		m.insert(make_pair("string", "×Ö·û´®"));
		m.insert(make_pair("count", "¼ÆÊý"));

		map<string,string>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		/*for (auto e : m)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}
}

