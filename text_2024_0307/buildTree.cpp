//��ǰ��������������й��������
#include "Assistance.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
    {
        if (inbegin > inend)
            return nullptr;

        //������ĵ�һ���ڵ㴴�����ڵ�
        TreeNode* root = new TreeNode(preorder[prei]);
        //�ָ������������
        
        int rooti = inbegin;
        //�������Ӧ�ñ��ֳ��������Σ�[inbegin,rooti-1] rooti [rooti+1,inend]
        while (rooti <= inend)
        {
            if (inorder[rooti] == preorder[prei])
                break;
            else
                rooti++;
        }

        ++prei;
        root->left = _buildTree(preorder, inorder, prei, inbegin, rooti - 1);
        root->right = _buildTree(preorder, inorder, prei, rooti + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};