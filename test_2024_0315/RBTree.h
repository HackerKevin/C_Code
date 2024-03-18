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

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;// ���ڵ����ɫΪ��ɫ
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
private:
	Node* _root = nullptr;

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

	}
};

void Test_RBTree1()
{
	int a[] = { 16,3,7,11,9,26,18,14,15 };
	int b[] = { 4,2,6,1,3,5,15,7,16,14 };
	RBTree<int, int> t1;
	for (auto e : b)
	{
		t1.Insert(make_pair(e, e));
		/*cout << e << "���룺" << t1.IsBalance() << endl;*/
	}
	t1.InOrder();
	/*cout << t1.IsBalance() << endl;*/
}

void Test_RBTree2()
{
	RBTree<int, int> t;
	srand(time(0));
	const size_t N = 100000;
	
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand();
		t.Insert(make_pair(x, x));
		/*cout << x << "���룺" << t.IsBalance() << endl;*/
		/*cout << t.IsBalance() << endl;*/
	}
	t.InOrder();
	/*cout << t.IsBalance() << endl;*/
}