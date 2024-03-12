#pragma once
#include "Assistance.h"

// AVL 树节点的定义
template<class K, class V>
class AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;// 平衡因子

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
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

		// 开始调整节点的平衡因子
		// 更新平衡因子：
		// 如果更新完以后，平衡因子没有出现问题，说明插入对树的平衡结构无影响，不需要处理
		// 如果更新完以后，平衡因子出现问题，那么平衡结构受到影响，需要处理——————>旋转
		// 插入新增节点，会影响沿路节点的平衡因子，这就是加 parent 的原因，方便向上更新平衡因子
		// 1.如果 cur == parent->right，parent->bf ++
		// 2.如果 cur == parent->left，parent->bf --
		// 更新完以后，parent 所在子树的高度是否变化决定了是否要继续向上更新
		// 1.parent->bf == 1 || parent->bf == -1，说明插入前 parent 的平衡因子为0，即插入前左右两边高度相等，现在有一边高1，所以要继续向上更新
		// 2.parent->bf == 2 || parent->bf == -2，说明 parent 所在子树不平衡，需要处理（旋转）这棵子树
		// 3.parent->bf == 0，说明 parent 所在子树的高度不变，不需要继续往上更新，此次插入结束

		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;

			}
			if (parent->bf == 1 || parent->bf == -1)
			{
				// 继续更新
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->bf == 0)
			{
				break;
			}
			else if (parent->bf == 2 || parent->bf == -2)
			{
				// 旋转处理
				// 旋转的目的：
				// 1.让这棵树平衡
				// 2.降低这棵树的高度
				break;
			}
			else
			{
				// 走到这里，说明插入之前就出问题了
				assert(false);
			}
		}
		return ture;
	}
private:

};