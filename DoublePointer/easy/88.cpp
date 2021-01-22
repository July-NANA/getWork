#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1;
        while (p2 >= 0)
        {
            if (p1 >= 0)
            {
                if (nums1[p1] <= nums2[p2])
                {
                    nums1.pop_back();
                    nums1.insert(nums1.begin() + p1 + 1, nums2[p2]);
                    p2--;
                }
                else
                {
                    p1--;
                }
            }
            else
            {
                /* if (nums1[p1] <= nums2[p2])
                {
                    nums1.insert(nums1.begin() + p1 + 1, nums2[p2]);
                    nums1.pop_back();
                    p2--;
                }
                else
                {
                    nums1.insert(nums1.begin() + p1, nums2[p2]);
                    nums1.pop_back();
                    p2--;
                } */
                nums1.insert(nums1.begin() + p1 + 1, nums2[p2]);
                nums1.pop_back();
                p2--;
            }
        }
    }
};

int main()
{
    Solution lab;
    /* vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    int m = 3, n = 3; */
    vector<int> nums1 = {2, 0}, nums2 = {1};
    int m = 1, n = 1;
    lab.merge(nums1, m, nums2, n);
    return 0;
}