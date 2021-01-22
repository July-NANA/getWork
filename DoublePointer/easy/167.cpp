#include <bits/stdc++.h>
using namespace std;

/* 双指针，一左一右 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        int right = numbers.size() - 1, left = 0;
        int sum = numbers[left] + numbers[right];
        while (right > left && sum != target)
        {

            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            sum = numbers[left] + numbers[right];
        }
        result.push_back(left + 1);
        result.push_back(right + 1);
        return result;
    }
};

int main()
{
    Solution lab;
    vector<int> test = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = lab.twoSum(test, target);
    return 0;
}