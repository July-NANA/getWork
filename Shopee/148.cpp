#include <bits/stdc++.h>
using namespace std;

/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        int length = 0;
        ListNode *res = new ListNode(0, head);
        int intv = 1;
        ListNode *h1, *h2, *h, *pre;
        ListNode *node = head;
        //统计链表长度
        while (node != nullptr)
        {
            ++length;
            node = node->next;
        }

        while (intv < length)
        {
            /* code */
            pre = res;
            h = res->next;
            //开始排序
            while (h != nullptr)
            {

                // 分割h1，h2
                int i = intv;
                h1 = h;
                while (i > 0 && h != nullptr)
                {
                    h = h->next;
                    --i;
                }
                if (i > 0)
                {
                    break;
                }
                i = intv;
                h2 = h;
                while (i > 0 && h != nullptr)
                {
                    h = h->next;
                    --i;
                }

                //合并
                int c1 = intv, c2 = intv - i;
                while (c1 > 0 && c2 > 0)
                {
                    if (h1->val < h2->val)
                    {
                        pre->next = h1;
                        h1 = h1->next;
                        --c1;
                    }
                    else
                    {
                        pre->next = h2;
                        h2 = h2->next;
                        --c2;
                    }
                    pre = pre->next;
                }
                pre->next = c1 == 0 ? h2 : h1;
                while (c1 > 0 || c2 > 0)
                {
                    pre = pre->next;
                    --c1;
                    --c2;
                }
                pre->next = h;
                //合并结束
            }
            //一次归并结束
            intv *= 2;
        }
        return res->next;
    }
};