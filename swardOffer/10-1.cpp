#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int constant = 1000000007;

public:
    //递归解决
    int fib(int n)
    {
        int result = 0;
        int f0 = 0, f1 = 1;
        int count = 1;
        if (n == 0)
        {
            return f0;
        }
        if (n == 1)
        {
            return f1;
        }

        result = num(f0, f1, n, count);
        return result;
    }
    int num(int f1, int f2, int n, int count)
    {
        int next = 0;
        next = f1 + f2;
        next = next % constant;
        ++count;
        if (count == n)
        {
            return next;
        }

        int result = num(f2, next, n, count);
        return result;
    }

    // 非递归解决
    int fib_1(int n)
    {
        int constant = 1000000007;
        int first = 0;
        int second = 1;
        while (n-- > 0)
        {
            int temp = first + second;
            first = second % constant;
            second = temp % constant;
        }
        return first;
    }
};

int main()
{
    Solution lab;
    int n = 45;
    int num = lab.fib(n);
    cout << num << endl;
    return 0;
}