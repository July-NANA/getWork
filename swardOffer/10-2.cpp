#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    该方法计算组合数时，若数据较大则容易溢出

    int numWays(int n)
    {
        //2的最大个数
        int n2 = n / 2;
        //1的最少个数
        int n1 = n - 2 * n2;
        int count = 0;
        //i:i个2的方法个数
        int c = 0;
        for (int i = 0; i <= n2; i++)
        {
            c = cn(n - i, i);
            count = (count + c) % 1000000007;
        }
        return count;
    }
    //n在下，m在上
    int cn(int n, int m)
    {
        int a = 1, b = 1;
        for (int i = 0; i < m; i++)
        {
            a = a * (n - i);
            b = b * (i + 1);
            // a = ((a % 1000000007) * ((n - i) % 1000000007)) % 1000000007;
            // b = ((b % 1000000007) * ((i + 1) % 1000000007)) % 1000000007;
        }
        int result = a / b;
        return result;
    }
*/

    // 动态规划：f(n)=f(n-1)+f(n-2)
    int numWays(int n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n <= 2)
        {
            return n;
        }
        int f1 = 1, f2 = 2;
        for (int i = 3; i <= n; i++)
        {
            int temp = f2;
            f2 = (f1 + temp) % 1000000007;
            f1 = temp;
        }
        return f2;
    }
};

int main(int argc, char const *argv[])
{
    Solution lab;
    int c = lab.numWays(7);
    cout << c << endl;
    return 0;
}
