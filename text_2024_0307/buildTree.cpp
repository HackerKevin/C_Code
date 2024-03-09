//从前序与中序遍历序列构造二叉树
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

        //用先序的第一个节点创建根节点
        TreeNode* root = new TreeNode(preorder[prei]);
        //分割出左右子区间
        
        int rooti = inbegin;
        //中序遍历应该被分成这样几段：[inbegin,rooti-1] rooti [rooti+1,inend]
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