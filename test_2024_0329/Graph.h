#pragma once
#include "Assistance.h"

namespace Martix
{
	template<class V, class W, W MAX_W = INT_MAX , bool Direction = false>
	class Graph
	{
	public:
		// ͼ�Ĵ���
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_martix.resize(n);
			for (size_t i = 0; i < _martix.size(); ++i)
			{
				_martix[i].resize(n, MAX_W);
			}
		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				//assert(false);
				throw invalid_argument("���㲻����");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_martix[srci][dsti] = w;

			// ����ͼ
			if (Direction == false)
			{
				_martix[dsti][srci] = w;
			}

		}

		void Print()
		{
			// ��ӡ����
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			
			// ��ӡ���±�
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << i << " ";
			}
			cout << endl;

			// ��ӡ����
			for (size_t i = 0; i < _martix.size(); ++i)
			{
				cout << i << " ";// ��ӡ���±�
				for (size_t j = 0; j < _martix[i].size(); ++j)
				{
					//cout << _martix[i][j] << " ";
					if (_martix[i][j] == MAX_W)
					{
						cout << "* ";
					}
					else
					{
						cout << _martix[i][j] << " ";
					}
				}
				cout << endl;
			}
			cout << endl;
		}
	private:
		vector<V> _vertexs;			// ���㼯��
		map<V, int>	_indexMap;		// �����Ӧ���±�
		vector<vector<W>> _martix;	// �ڽӾ���
	};

	void TestGraph()
	{
		Graph<char, int, INT_MAX, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);
		g.Print();
	}
}

