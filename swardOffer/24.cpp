#include <bits/stdc++.h>
using namespace std;

/* 
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 */

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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *h1 = nullptr, *h2 = head, *temp;
        while (h2 != nullptr)
        {
            temp = h2->next;
            h2->next = h1;
            h1 = h2;
            h2 = temp;
        }
        return h1;
    }
};