// 非递归实现树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;// 表示访问一棵树的开始
        vector<int> v;

        while (cur || !st.empty())// 栈不为空说明右子树还没有访问完
        {
            // 开始访问一棵树
            // 1.访问左路节点
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);// 入栈是为了方便访问它的右子树
                cur = cur->left;
            }
            // 2.访问左路节点的右子树
            // 优先访问栈顶的右子树
            TreeNode* top = st.top();
            st.pop();

            // 子问题访问右子树
            cur = top->right;
        }

        return v;
    }
};