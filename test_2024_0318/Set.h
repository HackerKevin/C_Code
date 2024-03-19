#pragma once
#include "RBTree.h"
namespace Kevin
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K,SetKeyOfT> _t;

	};

	void Test_Set()
	{
		set<int> s;
		s.insert(3);
		s.insert(1);
		s.insert(2);
	}
}

