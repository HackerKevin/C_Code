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
	Colour _col;// ��ɫ

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
			// �Ҳ�Ϊ�գ���һ������������������ڵ�
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			// ��Ϊ�գ����ŵ�����·���Һ����Ǹ�����ĺ��ӵ�����

		}
		
	return *this;
	}
};

// �º���
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
			_root->_col = BLACK;// ���ڵ����ɫΪ��ɫ
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

		cur->_parent = parent;// �������Ӹ��ڵ�

		// ÿ�������Ľڵ��Ǻ�ɫ�������Ҫ���д���
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;// parent �Ǻ�ɫ���游һ������
			if (grandfather->_left == parent)// ����������游����ߣ����������游���ұ�
			{
				Node* uncle = grandfather->_right;
				// ���һ����������������ɫ�Ǻ�ɫ���򽫸��׺��������ɫ��ڣ����游���
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}


				// �������������岻���ڻ����������Ϊ�ڣ����һ�仯�����������ױ�ڣ��游��죬����������жϽ��е�������˫��
				else
				{
					//     g                                      p
					//   p  u   ����������� g Ϊ����������     c   g
					//  c                                            u
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//     g                                                      
					//   p   u   ������������� p Ϊ�������������ٶ� g ��������
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

			// ����������游���ұߣ����������游�����
			else
			{
				Node* uncle = grandfather->_left;
				// ���һ����������������ɫ�Ǻ�ɫ���򽫸��׺��������ɫ��ڣ����游���
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}


				// �������������岻���ڻ����������Ϊ�ڣ����һ�仯�����������ױ�ڣ��游��죬����������жϽ��е�������˫��
				else
				{
					//     g
					//   u  p   ����������� g Ϊ����������
					//       c                                    
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//     g                                                      
					//   u   p   ������������� p Ϊ�������������ٶ� g ��������
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
			cout << "���ڵ����ɫ�Ǻ�ɫ" << endl;
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
		// ����Ƿ���������ĺ�ɫ�ڵ�
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
				cout << "ĳ��·����ɫ�ڵ�����������" << endl;
				return false;
			}
			return true;
		}


		if (root->_col == BLACK)
			++blackNum;
		if (root->_col == RED && root->_parent->_col == RED && root->_parent)
		{
			cout << "���������ĺ�ɫ�ڵ�" << endl;
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
		if (subRL)// subRL ��Ϊ�ղŵ���
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (ppnode == nullptr)// ppnode Ϊ��˵�� parent ���ǿսڵ㣬��ת�� subR ��Ϊ��
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else// ������ȷ�� parent �������ٽ��е���
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
//		/*cout << e << "���룺" << t1.IsBalance() << endl;*/
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
//		/*cout << x << "���룺" << t.IsBalance() << endl;*/
//		/*cout << t.IsBalance() << endl;*/
//	}
//	//t.InOrder();
//	cout << t.IsBalance() << endl;
//	cout << t.Height() << endl;
//}