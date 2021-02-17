#include <bits/stdc++.h>
using namespace std;

/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 小数点只有一个且在e强
// e的前后是整数
// 正负号必须在最左侧或者e后第一位

class Solution
{
public:
    bool isNumber(string s)
    {
        if (s.empty())
            return false;
        //去除空格
        while (s.length() > 0 && s[0] == ' ')
            s.erase(0, 1);
        while (s.length() > 0 && s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1);
        if (s.length() == 0)
            return false;
        //执行判断
        bool isDot = false, isE = false, isNumber = false;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
                return false;

            // 判断数值
            else if (s[i] >= '0' && s[i] <= '9')
                isNumber = true;
            // 判断e
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (isE || !isNumber || i == s.length() - 1)
                    return false;
                s[i] = 'e'; // 将'E'变成'e'
                isE = true;
            }
            // 判断正负号
            else if (s[i] == '+' || s[i] == '-')
            {
                // 如果正负号不在首位和e后第一位或在末位，则不是
                if ((i > 0 && s[i - 1] != 'e') || (i == s.length() - 1))
                    return false;
            }
            // 判断小数点
            else if (s[i] == '.')
            {
                /* 如果 
                已存在小数点
                已经存在e
                小数点单独出现
                则不是
                */
                if (isDot || isE || (i == s.length() - 1 && !isNumber))
                    return false;
                isDot = true;
            }
            // 如果是其它符号
            else
                return false;
        }
        return true;
    }
};
