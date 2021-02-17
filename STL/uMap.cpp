#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
    unordered_map<char, int> dic;
    //哈希表的遍历是无序的

    //插入操作
    dic.insert({'a', 1});
    dic.insert({'b', 2});
    dic.insert({'e', 5});
    dic.insert(make_pair('c', 3));
    dic.insert(make_pair('d', 4));
    dic.insert(pair('h', 7));
    dic['f'] = 6;
    // for (unordered_map<char, int>::iterator it = dic.begin(); it != dic.end(); it++)
    // {
    //     cout << (*it).first << (*it).second << endl;
    // }
    cout << dic['h'] << endl;

    return 0;
}
