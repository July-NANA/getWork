#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int length = numbers.size() - 1;
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] > numbers[i + 1])
                return numbers[i + 1];
        }
        return numbers[0];
    }
};

//方法二：二分查找
