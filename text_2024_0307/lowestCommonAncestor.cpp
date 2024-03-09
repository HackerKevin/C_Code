#include "Assistance.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    //GetPath 用来求路径,其中 path 为输出型参数，x 为要找的节点
    bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == nullptr)
            return false;

        //如果根不为空，那么不管根节点是不是要找的节点先让它入栈
        path.push(root);
        //如果根节点刚好是要找的节点，直接返回 true
        if (root == x)
            return true;

        //如果没有找到，就先递归到左树去找，如果找到了，就用 true 返回上一层
        if (GetPath(root->left, x, path))
            return true;

        //如果在左树没有找到就再到右树去找
        if (GetPath(root->right, x, path))
            return true;

        //走到这里,说明这个节点以及它的左子树和右子树均没有找到的节点，则将该节点出栈，并用false返回上一层
        path.pop();
        return false;

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> pPath, qPath;

        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        //走到这里，先让两个栈的长度相等
        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
                pPath.pop();
            else
                qPath.pop();
        }

        //走到这里，开始判断两个栈的栈顶元素是否相等，相等则说明该节点为最近公共祖先
        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};