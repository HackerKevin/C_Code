//102 二叉树的层序遍历
#include "Assistance.h"
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int levelSize = 0;
        if (root)//如果根不为空，就入队列
        {
            q.push(root);
            levelSize = 1;
        }

        vector<vector<int>> vv;//用来存放一层一层出的节点
        while (!q.empty())//如果队列不等于空，就说明树还没有被遍历完
        {
            //通过levelSize控制一层一层出
            vector<int> v;//用来存放每一层的数据
            while (levelSize--)//levelSize是几循环就执行几次，--levelSize表示的则是执行（levelSize - 1）次
            {
                TreeNode* front = q.front();//先取队头的数据
                q.pop();
                v.push_back(front->val);
                //进去的同时把该节点的下一层往队列里面带

                if (front->left)//左如果不为空就让左入队列
                    q.push(front->left);

                if (front->right)//右如果不为空就让右入队列
                    q.push(front->right);

            }
            //走到这里就说明当前层已经出完了，就把当前层所出的数据放到vv里面
            vv.push_back(v);
            //更新下一层的数据
            levelSize = q.size();
        }
        return vv;
    }
};