#include <bits/stdc++.h>
using namespace std;

/* 
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 2 个节点是值为 4 的节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* 
设置前后两个节点h1和h2，当h2的下标为k时，h1开始自增，当h2的为尾节点时停止
 */
class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }

        unordered_map<int, ListNode *> myMap;
        int nodeLength = 1;
        while (head != nullptr)
        {
            myMap.insert({{nodeLength, head}});
            ++nodeLength;
            head = head->next;
        }
        if (nodeLength < k)
        {
            return nullptr;
        }

        ListNode *res = myMap[nodeLength - k];
        return res;
    }
};