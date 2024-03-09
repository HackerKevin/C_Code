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
    //prev ��Ҫ�����ã���Ϊ cur ���µݹ��ʱ��Ὺ���µ�ջ֡����ô��ͬ��ջ֡����� prev Ӧ���ǲ�ͬ��
    void InOrderConvert(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
            return;

        //cur �����Ϊ�գ��Ϳ�ʼ������
        InOrderConvert(cur->left, prev);
        
        //�ߵ�������� cur �� left �� prev �� right ��ָ��
        cur->left = prev;
        //prev Ҫ���ܿղ��ܸ�
        if (prev)
            prev->right = cur;

        //cur �����ݹ������ߣ���������֮ǰ�� cur ���� prev
        prev = cur;

        InOrderConvert(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {

        TreeNode* prev = nullptr;
        InOrderConvert(pRootOfTree, prev);

        //�ߵ������ʱ���Ѿ������������Ҫ���ص������ͷ����ô���ǿ����ø��ڵ�һֱ��ǰ�������ҵ�ͷ�ڵ�
        TreeNode* head = pRootOfTree;
        //ֻҪ head �� head ��ǰһ���ڵ㲻Ϊ�գ���һֱ��ǰ�ߣ�ֱ���ҵ�ͷ
        while (head && head->left)
            head = head->left;

        return head;
    }
};