#pragma once
#include "Assistance.h"

// AVL ���ڵ�Ķ���
template<class K,class V>
class AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;// ƽ������

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
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

		cur->_parent = parent;// �������Ӹ��ڵ�

		// ��ʼ�����ڵ��ƽ������
		// ����ƽ�����ӣ�
		// ����������Ժ�ƽ������û�г������⣬˵�����������ƽ��ṹ��Ӱ�죬����Ҫ����
		// ����������Ժ�ƽ�����ӳ������⣬��ôƽ��ṹ�ܵ�Ӱ�죬��Ҫ����������������>��ת
		// ���������ڵ㣬��Ӱ����·�ڵ��ƽ�����ӣ�����Ǽ� parent ��ԭ�򣬷������ϸ���ƽ������
		// 1.��� cur == parent->right��parent->bf ++
		// 2.��� cur == parent->left��parent->bf --
		// �������Ժ�parent ���������ĸ߶��Ƿ�仯�������Ƿ�Ҫ�������ϸ���
		// 1.parent->bf == 1 || parent->bf == -1��˵������ǰ parent ��ƽ������Ϊ0��������ǰ�������߸߶���ȣ�������һ�߸�1������Ҫ�������ϸ���
		// 2.parent->bf == 2 || parent->bf == -2��˵�� parent ����������ƽ�⣬��Ҫ��������ת���������
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
			if (parent->bf == 1 || parent->bf == -1)
			{
				// ��������
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->bf == 0)
			{
				break;
			}
			else if (parent->bf == 2 || parent->bf == -2)
			{
				// ��ת����
				// ��ת��Ŀ�ģ�
				// 1.�������ƽ��
				// 2.����������ĸ߶�
				break;
			}
			else
			{
				// �ߵ����˵������֮ǰ�ͳ�������
				assert(false);
			}
		}
		return ture;
	}
private:

};