//102 �������Ĳ������
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
        if (root)//�������Ϊ�գ��������
        {
            q.push(root);
            levelSize = 1;
        }

        vector<vector<int>> vv;//�������һ��һ����Ľڵ�
        while (!q.empty())//������в����ڿգ���˵������û�б�������
        {
            //ͨ��levelSize����һ��һ���
            vector<int> v;//�������ÿһ�������
            while (levelSize--)//levelSize�Ǽ�ѭ����ִ�м��Σ�--levelSize��ʾ������ִ�У�levelSize - 1����
            {
                TreeNode* front = q.front();//��ȡ��ͷ������
                q.pop();
                v.push_back(front->val);
                //��ȥ��ͬʱ�Ѹýڵ����һ�������������

                if (front->left)//�������Ϊ�վ����������
                    q.push(front->left);

                if (front->right)//�������Ϊ�վ����������
                    q.push(front->right);

            }
            //�ߵ������˵����ǰ���Ѿ������ˣ��Ͱѵ�ǰ�����������ݷŵ�vv����
            vv.push_back(v);
            //������һ�������
            levelSize = q.size();
        }
        return vv;
    }
};