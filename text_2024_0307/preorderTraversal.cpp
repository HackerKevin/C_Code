// �ǵݹ�ʵ������ǰ�����
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
                cur = cur->left;
            }
            // 2.������·�ڵ��������
            // ���ȷ���ջ����������
            TreeNode* top = st.top();
            st.pop();

            // ���������������
            cur = top->right;
        }

        return v;
    }
};