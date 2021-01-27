#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> result;
        if (head == nullptr)
        {
            return result;
        }

        ListNode *temp = head;
        int length = 0;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            ++length;
        }

        for (int i = 0; i <= length; i++)
        {
            result.insert(result.begin(), head->val);
            head = head->next;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution lab;

    return 0;
}
