#include "Assistance.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    //GetPath ������·��,���� path Ϊ����Ͳ�����x ΪҪ�ҵĽڵ�
    bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == nullptr)
            return false;

        //�������Ϊ�գ���ô���ܸ��ڵ��ǲ���Ҫ�ҵĽڵ���������ջ
        path.push(root);
        //������ڵ�պ���Ҫ�ҵĽڵ㣬ֱ�ӷ��� true
        if (root == x)
            return true;

        //���û���ҵ������ȵݹ鵽����ȥ�ң�����ҵ��ˣ����� true ������һ��
        if (GetPath(root->left, x, path))
            return true;

        //���������û���ҵ����ٵ�����ȥ��
        if (GetPath(root->right, x, path))
            return true;

        //�ߵ�����,˵������ڵ��Լ���������������������û���ҵ��Ľڵ㣬�򽫸ýڵ��ջ������false������һ��
        path.pop();
        return false;

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> pPath, qPath;

        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        //�ߵ������������ջ�ĳ������
        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
                pPath.pop();
            else
                qPath.pop();
        }

        //�ߵ������ʼ�ж�����ջ��ջ��Ԫ���Ƿ���ȣ������˵���ýڵ�Ϊ�����������
        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};