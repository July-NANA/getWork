#include <bits/stdc++.h>
using namespace std;

/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/

/*
 思路：
 双指针法：一前一后向中间靠拢，偶数在前则交换，
 如果右指针为奇数，左指针不是偶数，左指针右移，直至左指针为偶数，交换，右指针左移。
*/
class Solution
{
public:
    // 判断是否为偶数
    bool isEven(int num)
    {
        int n = num % 2;
        if (n == 1)
        {
            return false;
        }
        if (n == 0)
        {
            return true;
        }
    }
    vector<int> exchange(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int temp = 0;
        while (left <= right)
        {
            // 如果左指针是偶数
            if (isEven(nums[left]))
            {
                // 如果右指针是奇数，交换
                if (!isEven(nums[right]))
                {
                    temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    //交换完成，左指针右移，右指针左移
                    ++left;
                    --right;
                }
                else
                { //右指针是偶数，右指针左移，直至右指针为奇数
                    --right;
                }
            }
            // 如果左指针是奇数
            if (!isEven(nums[left]))
            {
                // 左指针右移，直至左指针为偶数
                ++left;
            }
        }
        return nums;
    }
};