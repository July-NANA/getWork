#include <bits/stdc++.h>
using namespace std;

//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        do
        {
            if (!fast || !fast->next)
            {
                return nullptr;
            }
        }
    }
};