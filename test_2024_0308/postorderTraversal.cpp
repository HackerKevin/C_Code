// �������ǵݹ�������
// ˼·�����������ã�����ǰ�����΢��һ�º�������
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
        TreeNode* cur = root;// ��ʾ����һ�����Ŀ�ʼ
        vector<int> v;

        while (cur || !st.empty())// ջ��Ϊ��˵����������û�з�����
        {
            // ��ʼ����һ����
            // 1.������·�ڵ�
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);// ��ջ��Ϊ�˷����������������
                cur = cur->right;
            }
            // 2.������·�ڵ��������
            // ���ȷ���ջ����������
            TreeNode* top = st.top();
            st.pop();

            // ���������������
            cur = top->left;
        }

        reverse(v.begin(), v.end());
        return v;
    }
};