#pragma once
#include "Assistance.h"

enum Colour
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;// ��ɫ

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->col = BLACK;// ���ڵ����ɫΪ��ɫ
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		cur->_parent = parent;// �������Ӹ��ڵ�

		// ÿ�������Ľڵ��Ǻ�ɫ�������Ҫ���д���
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;// parent �Ǻ�ɫ���游һ������
			if (grandfather->_left == parent)// ����������游����ߣ����������游���ұ�
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				// ��������������ɫ�Ǻ�ɫ���򽫸��׺��������ɫ��ڣ����游���
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				
				// ������岻���ڻ����������Ϊ�ڣ����ױ�ڣ��游��죬��������ת
			}

		}

		_root->_col = BLACK;
		return true;
	}
private:
	Node* _root;
};