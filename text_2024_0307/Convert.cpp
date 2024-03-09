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
    //prev 需要加引用，因为 cur 往下递归的时候会开辟新的栈帧，那么不同的栈帧里面的 prev 应该是不同的
    void InOrderConvert(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
            return;

        //cur 如果不为空，就开始走中序
        InOrderConvert(cur->left, prev);
        
        //走到这里，调整 cur 的 left 和 prev 的 right 的指向
        cur->left = prev;
        //prev 要不能空才能改
        if (prev)
            prev->right = cur;

        //cur 继续递归往下走，所以在走之前将 cur 赋给 prev
        prev = cur;

        InOrderConvert(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {

        TreeNode* prev = nullptr;
        InOrderConvert(pRootOfTree, prev);

        //走到这里，此时树已经变成了链表，需要返回到链表的头，那么我们可以用根节点一直往前面走来找到头节点
        TreeNode* head = pRootOfTree;
        //只要 head 和 head 的前一个节点不为空，就一直往前走，直到找到头
        while (head && head->left)
            head = head->left;

        return head;
    }
};