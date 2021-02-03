#include <bits/stdc++.h>
using namespace std;

/*
n>1,m>1
f(2)=1,
f(3)={1*2, 1*1*1}=2
f(4)={1*3, 1*1*2,1*1*1*1, 2*2}=4
f(5)={1*4, 1*1*3,1*1*1*2,1*1*1*1*1,2*3}=6
f(6)={1*5, 1*1*4, 1*1*1*3, 1*1*1*1*2, 1*1*1*1*1*1, 1*2*3}=6=1*f(5)
f(7)=2*2*3=12=2*f(5)
f(8)=2*3*3=18=3*f(5)

*/
class Solution
{
public:
    //  求 (x^a) % p —— 循环求余法
    // int remainder(int x, int a, int p)
    // {
    //     int rem = 1;
    //     for (int i = 0; i < a; i++)
    //     {
    //         rem = (rem * x) % p;
    //     }
    //     return rem;
    // }

    // 快速幂求余
    int remainder(int x, int a, int p)
    {
        long rem = 1;
        while (a > 0)
        {
            if (a % 2 == 1)
            {
                /* code */
                rem = (rem * x) % p;
            }
            x = (x * x) % p;
            a = a / 2;
        }
        return (int)(rem % p);
    }
    int cuttingRope(int n)
    {
        int p = 1000000007;
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }
        int num_3 = 0, num_2 = 0;
        num_3 = n / 3;
        if (n % 3 == 1)
        {
            --num_3;
            num_2 += 2;
        }
        else if (n % 3 == 2)
        {
            ++num_2;
        }
        int max = 0;
        max = remainder(3, num_3, p) * remainder(2, num_2, p);
        return max;
    }
};
