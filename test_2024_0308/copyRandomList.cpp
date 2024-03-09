#include "Assistance.h"
#include "map"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        map<Node*, Node*> copyNodeMap;
        Node* cur = head;
        Node* copyhead, * copytail;
        copyhead = copytail = nullptr;

        while (cur)
        {
            Node* copy = new Node(cur->val);
            copyNodeMap[cur] = copy;

            if (copytail == nullptr)
            {
                copytail = copyhead = copy;
            }
            else
            {
                copytail->next = copy;
                copytail = copytail->next;
            }
            cur = cur->next;
        }
        cur = head;
        Node* copy = copyhead;
        while (cur)
        {
            if (cur->random == nullptr)
            {
                copy->random = nullptr;
            }
            else
            {
                copy->random = copyNodeMap[cur->random];
            }
            cur = cur->next;
            copy = copy->next;
        }
        return copyhead;
    }
};

int main()
{
    Node a1(1);
    Node a2(2);
    Node a3(3);
    Node a4(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a1.random = &a3;
    a2.random = &a1;
    a3.random = &a2;
    a4.random = &a1;
    Solution solution;
    solution.copyRandomList(&a1);
    return 0;
}