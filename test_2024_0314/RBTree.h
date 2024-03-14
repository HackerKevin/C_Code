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
	Colour _col;// 颜色

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
			_root->col = BLACK;// 根节点的颜色为黑色
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

		cur->_parent = parent;// 反向链接父节点

		// 每次新增的节点是红色，因此需要进行处理
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;// parent 是红色则祖父一定存在
			if (grandfather->_left == parent)// 如果父亲在祖父的左边，则叔叔在祖父的右边
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				// 如果叔叔存在且颜色是红色，则将父亲和叔叔的颜色变黑，把祖父变红
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				
				// 如果叔叔不存在或叔叔存在且为黑，则父亲变黑，祖父变红，并进行旋转
			}

		}

		_root->_col = BLACK;
		return true;
	}
private:
	Node* _root;
};