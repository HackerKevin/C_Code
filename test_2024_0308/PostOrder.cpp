// 非递归实现二叉树后序遍历II
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;

        TreeNode* prev = nullptr;
        while (cur || !st.empty())// 栈不为空说明右子树还没有访问完
        {
            // 开始访问一棵树
            // 1.访问左路节点
            while (cur)
            {
                st.push(cur);// 入栈是为了方便访问它的右子树
                cur = cur->left;
            }
            // 2.访问左路节点的右子树
            // 优先访问栈顶的右子树
            TreeNode* top = st.top();

            //右为空，或者右子树已经访问过了（上一个访问的节点是右子树的根），则可以访问根节点
            if (top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                st.pop();

                prev = top;
            }
            // 子问题访问右子树
            else
            {
                cur = top->right;
            }
                
        }

        return v;
    }
};