#pragma once
#include "Assistance.h"

enum Colour
{
	RED,
	BLACK,
};


template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;// 颜色

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template <class T,class Ref,class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// 右不为空，下一个就是右子树的最左节点
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			// 右为空，沿着到根的路径找孩子是父亲左的孩子的祖先

		}
		
	return *this;
	}
};

// 仿函数
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T,const T&,const T*> const_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		/*Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}*/
		return iterator(nullptr);
	}

	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_kv._data) < key)
				cur = cur->_right;

			else if (kot(cur->_kv._data) > key)
				cur = cur->_left;

			else
				return cur;
		}

		return nullptr;
	}
	int Height()
	{
		return _Height(_root);
	}

	/*void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}*/

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;// 根节点的颜色为黑色
			return true;
		}

		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		if (kot(parent->_data) > kot(data))
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
				// 情况一：如果叔叔存在且颜色是红色，则将父亲和叔叔的颜色变黑，把祖父变红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}


				// 情况二：如果叔叔不存在或叔叔存在且为黑（情况一变化而来），则父亲变黑，祖父变红，并根据情况判断进行单旋还是双旋
				else
				{
					//     g                                      p
					//   p  u   这种情况下以 g 为轴点进行右旋     c   g
					//  c                                            u
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//     g                                                      
					//   p   u   这种情况下先以 p 为轴点进行左旋，再对 g 进行右旋
					//    c    
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						parent->_col = RED;
						grandfather->_col = RED;
					}

					break;
				}
			}

			// 如果父亲在祖父的右边，则叔叔在祖父的左边
			else
			{
				Node* uncle = grandfather->_left;
				// 情况一：如果叔叔存在且颜色是红色，则将父亲和叔叔的颜色变黑，把祖父变红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}


				// 情况二：如果叔叔不存在或叔叔存在且为黑（情况一变化而来），则父亲变黑，祖父变红，并根据情况判断进行单旋还是双旋
				else
				{
					//     g
					//   u  p   这种情况下以 g 为轴点进行左旋
					//       c                                    
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//     g                                                      
					//   u   p   这种情况下先以 p 为轴点进行右旋，再对 g 进行左旋
					//      c    
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						parent->_col = RED;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;
		return true;
	}

	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			cout << "根节点的颜色是红色" << endl;
			return false;
		}

		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}
		// 检查是否存在连续的红色节点
		return _Check(_root, 0, benchmark);


	}
private:
	Node* _root = nullptr;

	void _Destroy(Node* root)
	{
		if (root == nullptr)
			return;

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _Check(Node* root, int blackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "某条路径黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}


		if (root->_col == BLACK)
			++blackNum;
		if (root->_col == RED && root->_parent->_col == RED && root->_parent)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return _Check(root->_left, blackNum, benchmark)
			&& _Check(root->_right, blackNum, benchmark);
	}

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
	}

	void RotateL(Node* parent)
	{
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

	}

	/*void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}*/

	bool _IsBalance(Node* root)
	{

	}
};

//void Test_RBTree1()
//{
//	int a[] = { 16,3,7,11,9,26,18,14,15 };
//	int b[] = { 4,2,6,1,3,5,15,7,16,14 };
//	RBTree<int, int> t1;
//	for (auto e : b)
//	{
//		t1.Insert(make_pair(e, e));
//		/*cout << e << "插入：" << t1.IsBalance() << endl;*/
//	}
//	t1.InOrder();
//	cout << t1.IsBalance() << endl;
//}
//
//void Test_RBTree2()
//{
//	RBTree<int, int> t;
//	srand(time(0));
//	const size_t N = 5000000;
//
//	for (size_t i = 0; i < N; ++i)
//	{
//		size_t x = rand() + i;
//		t.Insert(make_pair(x, x));
//		/*cout << x << "插入：" << t.IsBalance() << endl;*/
//		/*cout << t.IsBalance() << endl;*/
//	}
//	//t.InOrder();
//	cout << t.IsBalance() << endl;
//	cout << t.Height() << endl;
//}