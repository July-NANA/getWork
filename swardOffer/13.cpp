#include <bits/stdc++.h>
using namespace std;

//方法一：深度优先搜索
//方法二：广度优先搜索

class Solution
{
public:
    // 方法一
    int movingCount(int m, int n, int k)
    {
        this->m = m;
        this->n = n;
        this->k = k;
        if (m <= 0 || n <= 0 || k <= 0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return movingCountCore(0, 0, visited);
    }

private:
    //m:行
    //n：列
    //k：参数
    int m, n, k;
    // int count = 0; //计数
    int movingCountCore(int i, int j, vector<vector<bool>> &visited)
    {
        int count = 0;
        if (!check(i, j, visited))
        {
            return count;
        }
        visited[i][j] = true;
        count = 1 +
                movingCountCore(i - 1, j, visited) +
                movingCountCore(i + 1, j, visited) +
                movingCountCore(i, j - 1, visited) +
                movingCountCore(i, j + 1, visited);
        return count;
    }

    // 获取各数位之和
    int getSum(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            sum = sum + num % 10;
            num /= 10;
        }
        return sum;
    }

    //检查该位置能否进入
    bool check(int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || getSum(i) + getSum(j) > k || visited[i][j])
        {
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution lab;
    int m = 3, n = 1, k = 0;
    int result = lab.movingCount(m, n, k);
    return 0;
}
