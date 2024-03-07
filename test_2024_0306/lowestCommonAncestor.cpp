#include "Assistance.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
   //IsInTree 实际上就相当于 Find，但是更简单，因为不需要返回指针
    bool IsInTree(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
            return false;
        if (root == x)
            return true;
        
        //走到这说明还没找到，需要递归到下一层
        return IsInTree(root->left, x) || IsInTree(root->right, x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //空树直接返回空
        if (root == nullptr)
            return nullptr;

        //如果 p 和 q 中有一个为根，则说明其中一个一定是另一个节点的孩子，那么公共祖先就是根
        if (p == root || q == root)
            return root;

        //走到这里，则说明 p 和 q 都不为根，那么就需要确定这两个节点在左树还是右树
        
        //pInleft 通过 IsInTree 来判断节点 p 是否在子树，pInRight 则一定是 pInLeft 的反
        bool pInLeft = IsInTree(root->left, p);
        bool pInRight = !pInLeft;

        //用同样的方式来判断 q 的位置
        bool qInLeft = IsInTree(root->left, q);
        bool qInRight = !qInLeft;

        //获取到 p 和 q 的位置之后，就可以开始判断它们之间的位置关系了

        //如果 p 在左而 q 在右或者 p 右而 q 在左，则说明当前这个节点就是它们的最近公共祖先
        if ((pInLeft && qInRight) || (pInRight && qInLeft))
            return root;

        //如果都在左，就需要递归到左子树去找
        else if (pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);

        //走到这里，则说明 p 和 q 都在右子树，就递归到右子树去找
        else
            return lowestCommonAncestor(root->right, p, q);

    }
};