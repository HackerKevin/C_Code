// �ǵݹ�ʵ�ֶ������������II
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
        while (cur || !st.empty())// ջ��Ϊ��˵����������û�з�����
        {
            // ��ʼ����һ����
            // 1.������·�ڵ�
            while (cur)
            {
                st.push(cur);// ��ջ��Ϊ�˷����������������
                cur = cur->left;
            }
            // 2.������·�ڵ��������
            // ���ȷ���ջ����������
            TreeNode* top = st.top();

            //��Ϊ�գ������������Ѿ����ʹ��ˣ���һ�����ʵĽڵ����������ĸ���������Է��ʸ��ڵ�
            if (top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                st.pop();

                prev = top;
            }
            // ���������������
            else
            {
                cur = top->right;
            }
                
        }

        return v;
    }
};