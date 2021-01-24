#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        vector<int> temp(nums.size());
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            ++temp[nums[i]];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp[i] > 1)
            {
                result.insert(result.end(), i);
            }
        }
        int num = result[0];
        return num;
    }

    int findRepeatNumber_2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution lab;
    vector<int> test = {2, 3, 1, 0, 2, 5, 3};
    int result = lab.findRepeatNumber_2(test);
    cout << result << endl;
    system("pause");
    return 0;
}
