#include "Assistance.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
   //IsInTree ʵ���Ͼ��൱�� Find�����Ǹ��򵥣���Ϊ����Ҫ����ָ��
    bool IsInTree(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
            return false;
        if (root == x)
            return true;
        
        //�ߵ���˵����û�ҵ�����Ҫ�ݹ鵽��һ��
        return IsInTree(root->left, x) || IsInTree(root->right, x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //����ֱ�ӷ��ؿ�
        if (root == nullptr)
            return nullptr;

        //��� p �� q ����һ��Ϊ������˵������һ��һ������һ���ڵ�ĺ��ӣ���ô�������Ⱦ��Ǹ�
        if (p == root || q == root)
            return root;

        //�ߵ������˵�� p �� q ����Ϊ������ô����Ҫȷ���������ڵ���������������
        
        //pInleft ͨ�� IsInTree ���жϽڵ� p �Ƿ���������pInRight ��һ���� pInLeft �ķ�
        bool pInLeft = IsInTree(root->left, p);
        bool pInRight = !pInLeft;

        //��ͬ���ķ�ʽ���ж� q ��λ��
        bool qInLeft = IsInTree(root->left, q);
        bool qInRight = !qInLeft;

        //��ȡ�� p �� q ��λ��֮�󣬾Ϳ��Կ�ʼ�ж�����֮���λ�ù�ϵ��

        //��� p ����� q ���һ��� p �Ҷ� q ������˵����ǰ����ڵ�������ǵ������������
        if ((pInLeft && qInRight) || (pInRight && qInLeft))
            return root;

        //��������󣬾���Ҫ�ݹ鵽������ȥ��
        else if (pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);

        //�ߵ������˵�� p �� q �������������͵ݹ鵽������ȥ��
        else
            return lowestCommonAncestor(root->right, p, q);

    }
};