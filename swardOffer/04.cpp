#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {

        //l:行
        //r：列
        /*
        从第一行开始，遍历第一行每一个数字，当与target相等时，返回true，不相等且下一个数字大于target时，跳转到下一行的该列
        重复之前的操作，直到遍历完整个数组
        */
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }

        int rows = matrix.size();
        int columns = matrix[0].size();
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            int num = matrix[row][column];
            if (num == target)
            {
                return true;
            }
            if (num > target)
            {
                --column;
            }
            if (num < target)
            {
                ++row;
            }
        }
        return false;

        // for (int l = 0; l < matrix.size() - 1; l++)
        // {
        //     if (r < matrix[0].size() - 1)
        //     {
        //         while (matrix[l][r + 1] <= target && r < matrix[0].size() - 1)
        //         {
        //             if (matrix[l][r] == target)
        //             {
        //                 return true;
        //             }
        //             // ++r;
        //             if (r < matrix[0].size() - 1)
        //             {
        //                 ++r;
        //             }
        //         }
        //     }

        //     if (matrix[l + 1][r] == target)
        //     {
        //         return true;
        //     }
        //     if (matrix[l + 1][r] > target)
        //     {
        //         return false;
        //     }
        // }
        // return false;
    }
};

int main()
{
    Solution lab;
    vector<vector<int>> matrix = {{-5}};
    int target = -10;
    bool result = lab.findNumberIn2DArray(matrix, target);
    cout << result << endl;
    return 0;
}
