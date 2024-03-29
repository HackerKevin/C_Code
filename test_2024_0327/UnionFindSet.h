#pragma once
#include "Assistance.h"

//template<class T>
//class UnionFindSet
//{
//public:
//	UnionFindSet(const T* a, size_t n)
//	{
//		for (size_t i = 0; i < n; ++i)
//		{
//			_a.push_back(a[i]);
//			_indexMap[a[i]] = i;
//		}
//	}
//private:
//	vector<T> _a;// 编号找人
//	map<T, int> _indexMap;// 人找编号
//};

template<class T>
class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{}

	void Union(int x1, int x2)// 合并
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// 如果根一样，说明本身就在一个集合，也就没必要合并
		if (root1 == root2)
			return;

		if (root1 > root2)// root1 比 root2 大时，说明 root1 的元素比 root2 的元素要少
		{
			swap(root1, root2);
		}

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}

	int FindRoot(int x)// 找根
	{
		int parent = x;
		while (_ufs[parent] >= 0)// 如果该元素不是根，那么就要去找它的根
		{
			parent = _ufs[parent];
		}
		return parent;
	}

	bool InSet(int x1, int x2)// 判断是否在同一集合
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	size_t SetSize()// 统计集合的数目
	{
		size_t size = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
				++size;
		}
		return size;
	}

private:
	vector<T> _ufs;// 编号找人
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		UnionFindSet<int> ufs(isConnected.size());
		for (size_t i = 0; i < isConnected.size(); ++i)
		{
			for (size_t j = 0; j < isConnected[i].size(); j++)
			{
				if (isConnected[i][j] == 1)
				{
					ufs.Union(i, j);
				}
			}
		}
		return ufs.SetSize();
	}
	
};