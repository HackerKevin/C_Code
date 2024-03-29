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
//	vector<T> _a;// �������
//	map<T, int> _indexMap;// ���ұ��
//};

template<class T>
class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{}

	void Union(int x1, int x2)// �ϲ�
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// �����һ����˵���������һ�����ϣ�Ҳ��û��Ҫ�ϲ�
		if (root1 == root2)
			return;

		if (root1 > root2)// root1 �� root2 ��ʱ��˵�� root1 ��Ԫ�ر� root2 ��Ԫ��Ҫ��
		{
			swap(root1, root2);
		}

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}

	int FindRoot(int x)// �Ҹ�
	{
		int parent = x;
		while (_ufs[parent] >= 0)// �����Ԫ�ز��Ǹ�����ô��Ҫȥ�����ĸ�
		{
			parent = _ufs[parent];
		}
		return parent;
	}

	bool InSet(int x1, int x2)// �ж��Ƿ���ͬһ����
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	size_t SetSize()// ͳ�Ƽ��ϵ���Ŀ
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
	vector<T> _ufs;// �������
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