//107 二叉树的层序遍历II
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
        //上面的代码全部复用106的
  
        reverse(vv.begin(), vv.end());//就加这一句即可

        return vv;
    }
};