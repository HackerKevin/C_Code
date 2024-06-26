#pragma once
#include "Assistance.h"

// AVL 树节点的定义
template<class K, class V>
struct AVLTreeNode
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

	int Height()
	{
		return _Height(_root);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}



	bool IsBalance()
	{
		return _IsBalance(_root);
	}

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
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续更新
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理
				// 旋转的目的：
				// 1.让这棵树平衡
				// 2.降低这棵树的高度
				if (parent->_bf == 2 && cur->_bf == 1)// 右边高就左单旋
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)// 左边高就右单旋
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
				{
					assert(false);
				}

				break;// 旋转完可以直接 break
			}
			else
			{
				// 走到这里，说明插入之前就出问题了
				assert(false);
			}
		}
		return true;
	}
private:

	Node* _root = nullptr;

private:
	// 左单旋
	void RotateL(Node* parent)
	{
		// 下面这样写没有维护 parent
		/*Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;*/

		// 这样写虽然维护了 parent 但是没有考虑 subRL 为空的情况
		/*Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		subRL->_parent = parent;
		subR->_left = parent;
		parent->_parent = subR;*/

		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppnode = parent->_parent;

		parent->_right = subRL;
		if (subRL)// subRL 不为空才调整
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (ppnode == nullptr)// ppnode 为空说明 parent 就是空节点，旋转后 subR 变为根
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else// 否则先确定 parent 的左右再进行调整
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}

			subR->_parent = ppnode;

		}

		parent->_bf = subR->_bf = 0;
	}

	// 右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppnode = parent->_parent;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (ppnode == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}

			subL->_parent = ppnode;

		}
		parent->_bf = subL->_bf = 0;
	}

	// 先左单旋再右单旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)// 右边高，说明插入在 c
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}

		else if (bf == -1)// 左边高，说明插入在 b
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}

		else if (bf == 0)// 说明 60 就是新增节点
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	//先右单旋再左单旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)// 右边高，说明插入在 c
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}

		else if (bf == -1)// 左边高，说明插入在 b
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}

		else if (bf == 0)// 说明 60 就是新增节点
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)// 空树可以认为是平衡树
			return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		// 检查平衡因子
		if (rightH - leftH != root->_bf)
		{
			cout << root->_kv.first << "节点平衡因子异常" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2// 高度差的绝对值小于2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}
public:


};

void Test_AVLTree1()
{
	int a[] = { 16,3,7,11,9,26,18,14,15 };
	int b[] = { 4,2,6,1,3,5,15,7,16,14 };
	AVLTree<int, int> t1;
	for (auto e : b)
	{
		t1.Insert(make_pair(e, e));
		cout << e << "插入：" << t1.IsBalance() << endl;
	}
	t1.InOrder();
	cout << t1.IsBalance() << endl;
}

//void Test_AVLTree2()
//{
//	srand(time(0));
//	const size_t N = 5000000;
//	AVLTree<int, int> t;
//	for (size_t i = 0; i < N; ++i)
//	{
//		size_t x = rand() + i;
//		t.Insert(make_pair(x, x));
//		/*cout << t.IsBalance() << endl;*/
//	}
//	//t.InOrder();
//	cout << t.IsBalance() << endl;
//	cout << t.Height() << endl;
//}