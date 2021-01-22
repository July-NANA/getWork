#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {

        if (nums.size() < 2)
        {
            return true;
        }
        int num = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                num++;
                if (num > 1)
                {
                    return false;
                }
                if (i >= 2 && nums[i - 2] > nums[i])
                {
                    nums[i] = nums[i - 1];
                }
                else
                {
                    nums[i - 1] = nums[i];
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution lab;
    vector<int> test = {4, 2, 1};
    bool re = lab.checkPossibility(test);
    cout << re << endl;
    return 0;
}