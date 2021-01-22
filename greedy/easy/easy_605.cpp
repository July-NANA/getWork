#include <bits/stdc++.h>
using namespace std;

//{1,0,0,0,0,1}
//{0,0,1,0,1}
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {

        if (flowerbed.size() < 2)
        {
            if (flowerbed[0] == 0 || n == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int befor = accumulate(flowerbed.begin(), flowerbed.end(), 0);
        int size = flowerbed.size();
        int after = 0;
        if (flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            after++;
        }
        if (flowerbed[size - 2] == 0)
        {
            flowerbed[size - 1] = 1;
            after++;
        }
        for (int i = 1; i < size - 1; i++)
        {
            /* code */
            if (flowerbed[i - 1] == 1)
            {
                flowerbed[i] = 0;
            }
            else if (flowerbed[i + 1] == 1)
            {
                /* code */
                flowerbed[i] = 0;
            }
            else
            {
                flowerbed[i] = 1;
            }
        }
        after = accumulate(flowerbed.begin(), flowerbed.end(), 0);
        int result = after - befor;
        if (result >= n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution lab;
    vector<int> test = {0, 0, 0, 1};
    int n = 1;
    int re = lab.canPlaceFlowers(test, n);
    cout << re << endl;
    return 0;
}