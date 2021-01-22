#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size < 2)
        {
            return size;
        }
        vector<int> num(size, 1);
        for (int i = 0; i < size - 1; i++)
        {
            /* code */
            if (ratings[i] < ratings[i + 1])
            {
                num[i + 1] = num[i] + 1;
            }
        }
        for (int i = size - 1; i > 0; i--)
        {
            /* code */
            if (ratings[i] < ratings[i - 1])
            {
                num[i - 1] = max(num[i - 1], num[i] + 1);
            }
        }
        return accumulate(num.begin(), num.end(), 0);
    }
    int candy_1(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size < 2)
        {
            return size;
        }
        vector<int> num(size, 1);
        for (int i = 1; i < size; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                num[i] = num[i - 1] + 1;
            }
        }
        for (int i = size - 1; i > 0; --i)
        {
            if (ratings[i] < ratings[i - 1])
            {
                num[i - 1] = max(num[i - 1], num[i] + 1);
            }
        }
        return accumulate(num.begin(), num.end(), 0); // std::accumulate 可以很方便 地求和 }
    }
};

int main()
{
    Solution lab;
    vector<int> test{1, 2, 87, 87, 87, 2, 1};
    int re = lab.candy(test);
    cout << re;
    system("pause");
    return 0;
}