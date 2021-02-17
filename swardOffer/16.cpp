#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double result = 0;
        if (n < 0)
        {
            if (x == 0.0)
            {
                return 0;
            }
            //大数求相反数
            unsigned int abs = (unsigned int)(n);
            result = Power(x, -abs);
            result = 1.0 / result;
            return result;
        }
        else
        {
            result = Power(x, n);
            return result;
        }
    }

    double Power(double x, unsigned int n)
    {
        if (n == 0)
        {
            return 1;
        }
        // double result = 0;
        double result = Power(x, n >> 1);
        result *= result;
        if (n % 2 == 1)
        {
            result *= x;
        }
        return result;
    }
};