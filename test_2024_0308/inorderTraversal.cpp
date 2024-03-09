// �������ǵݹ��������
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
            // 1.������·�ڵ�
            while (cur || !st.empty())
            {
                st.push(cur);
                cur = cur->left;

            }

            // ջ����ȡ����·�ڵ㣬�����ýڵ���������Ѿ���������
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            // ������·�ڵ��������
            cur = top->right;
          
        }
        return v;
    }
};