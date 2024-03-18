#pragma once
#include "Assistance.h"

// AVL ���ڵ�Ķ���
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;// ƽ������

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

		cur->_parent = parent;// �������Ӹ��ڵ�

		// ��ʼ�����ڵ��ƽ������
		// ����ƽ�����ӣ�
		// ����������Ժ�ƽ������û�г������⣬˵�����������ƽ��ṹ��Ӱ�죬����Ҫ����
		// ����������Ժ�ƽ�����ӳ������⣬��ôƽ��ṹ�ܵ�Ӱ�죬��Ҫ��������������>��ת
		// ���������ڵ㣬��Ӱ����·�ڵ��ƽ�����ӣ�����Ǽ� parent ��ԭ�򣬷������ϸ���ƽ������
		// 1.��� cur == parent->right��parent->bf ++
		// 2.��� cur == parent->left��parent->bf --
		// �������Ժ�parent ���������ĸ߶��Ƿ�仯�������Ƿ�Ҫ�������ϸ���
		// 1.parent->bf == 1 || parent->bf == -1��˵������ǰ parent ��ƽ������Ϊ0��������ǰ�������߸߶���ȣ�������һ�߸�1������Ҫ�������ϸ���
		// 2.parent->bf == 2 || parent->bf == -2��˵�� parent ����������ƽ�⣬��Ҫ������ת���������
		// 3.parent->bf == 0��˵�� parent ���������ĸ߶Ȳ��䣬����Ҫ�������ϸ��£��˴β������

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
				// ��������
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת����
				// ��ת��Ŀ�ģ�
				// 1.�������ƽ��
				// 2.����������ĸ߶�
				if (parent->_bf == 2 && cur->_bf == 1)// �ұ߸߾�����
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)// ��߸߾��ҵ���
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

				break;// ��ת�����ֱ�� break
			}
			else
			{
				// �ߵ����˵������֮ǰ�ͳ�������
				assert(false);
			}
		}
		return true;
	}
private:

	Node* _root = nullptr;

private:
	// ����
	void RotateL(Node* parent)
	{
		// ��������дû��ά�� parent
		/*Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;*/

		// ����д��Ȼά���� parent ����û�п��� subRL Ϊ�յ����
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

		parent->_bf = subR->_bf = 0;
	}

	// �ҵ���
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

	// ���������ҵ���
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)// �ұ߸ߣ�˵�������� c
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}

		else if (bf == -1)// ��߸ߣ�˵�������� b
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}

		else if (bf == 0)// ˵�� 60 ���������ڵ�
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

	//���ҵ���������
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)// �ұ߸ߣ�˵�������� c
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}

		else if (bf == -1)// ��߸ߣ�˵�������� b
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}

		else if (bf == 0)// ˵�� 60 ���������ڵ�
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
		if (root == nullptr)// ����������Ϊ��ƽ����
			return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		// ���ƽ������
		if (rightH - leftH != root->_bf)
		{
			cout << root->_kv.first << "�ڵ�ƽ�������쳣" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2// �߶Ȳ�ľ���ֵС��2
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
		cout << e << "���룺" << t1.IsBalance() << endl;
	}
	t1.InOrder();
	cout << t1.IsBalance() << endl;
}

void Test_AVLTree2()
{
	srand(time(0));
	const size_t N = 5000000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		/*cout << t.IsBalance() << endl;*/
	}
	//t.InOrder();
	cout << t.IsBalance() << endl;
	cout << t.Height() << endl;
}