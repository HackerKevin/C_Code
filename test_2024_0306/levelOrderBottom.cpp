//107 �������Ĳ������II
#include "Assistance.h"
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        int levelSize = 0;
        if (root)
        {
            q.push(root);
            levelSize = 1;
        }

        vector<vector<int>> vv;
        while (!q.empty())
        {
            
            vector<int> v;
            while (levelSize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);

            }
            vv.push_back(v);
            levelSize = q.size();
        }
        //����Ĵ���ȫ������106��
  
        reverse(vv.begin(), vv.end());//�ͼ���һ�伴��

        return vv;
    }
};