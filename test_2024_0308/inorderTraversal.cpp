// 二叉树非递归中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        while (cur)
        {
            // 1.访问左路节点
            while (cur || !st.empty())
            {
                st.push(cur);
                cur = cur->left;

            }

            // 栈里面取到左路节点，表明该节点的左子树已经访问完了
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            // 访问左路节点的右子树
            cur = top->right;
          
        }
        return v;
    }
};