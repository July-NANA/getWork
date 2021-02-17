#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        // 头节点为目标节点时
        if (head->val == val)
        {
            head = head->next;
            return head;
        }
        // 只有一个头节点，且不是目标时
        if (head->next == nullptr)
        {
            return head;
        }

        ListNode *node = head;
        while (node->next->val != val && node->next->next != nullptr) //下一个节点不是目标节点并且不是尾节点时
        {
            node = node->next;
        }
        // 循环结束之后node->next为当前节点
        if (node->next->next == nullptr && node->next->val != val) //尾节点非目标节点，即目标节点不存在
        {
            return head;
        }
        if (node->next->next == nullptr && node->next->val == val) //尾节点为目标节点，node->next为尾节点
        {
            /* code */
            node->next = nullptr;
            return head;
        }
        else
        { //目标节点不是尾节点
            node->next->next = node->next->next->next;
            return head;
        }
    }
};