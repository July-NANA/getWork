#include  <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.empty() || p.empty())
        {
            return false;
        }
        string::iterator st = s.begin();
        string::iterator pt = p.begin();
        return matchCore(st, pt);
    }

    /*
    思路：
    字符串中的当前字符为s
    模式中的当前字符为p

    模式中下一个字符是*：
        1.0个p：s!=p,p跳到下下个p+2；
        2.一个或多个p：s变为下一个，当s!=p且p!=.时，s+1，p+2；
    模式中下一个字符不是*：
        1.匹配：p==s或p==.;
        2.不匹配
    完成一次判断后递归

    成功：字符串匹配结束，模式也匹配结束
    失败：字符串未结束，模式已结束
    */
    // s: 字符串迭代器
    // p：模式迭代器
    bool matchCore(string::iterator &s, string::iterator &p)
    {
        if ((*s) == '\0' && (*p) == '\0') //成功
        {
            return true;
        }
        if ((*s) != '\0' && (*p) == '\0')
        {
            return false;
        }
        string::iterator t_1, t_2;
        if (*(p + 1) == '*')
        {
            // //情况1，0个p
            // if (*s != *p && *p != '.') //p不是.并且s不等于p
            // {
            //     p += 2;
            //     return matchCore(s, p);
            // }
            // // 情况2，多个p
            // else if (*p == '.' && *s != '\0') //p是.并且s没有结束
            // {
            //     s += 1;
            //     return matchCore(s, p);
            // }
            // else if (*p == '.' && *s == '\0')
            // {
            //     p += 2;
            //     return matchCore(s, p);
            // }

            // else if (*p != '.') //p不是.
            // {
            //     if (*p == *s)
            //     {
            //         s += 1;
            //         return matchCore(s, p);
            //     }
            //     else
            //     {
            //         s += 1;
            //         p += 2;
            //         return matchCore(s, p);
            //     }
            // }
            if (*p == *s || (*p == '.' && *s != '\0'))
            {
                // return  matchCore(t_1=s+1, t_2=p+2)|| matchCore(t_1=s+1, p) || matchCore(s, t_2=p+2);
                if (matchCore(t_1 = s + 1, t_2 = p + 2))
                {
                    return true;
                }
                else if (matchCore(t_1 = s + 1, p))
                {
                    return true;
                }
                else if (matchCore(s, t_2 = p + 2))
                {
                    return true;
                }
            }
            else
            {
                return matchCore(s, t_2 = p + 2);
            }
        }
        if (*s == *p || (*p == '.' && *s != '\0'))
        {
            s += 1;
            p += 1;
            return matchCore(s, p);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution lab;
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    bool result = lab.isMatch(s, p);
    cout << result << endl;
    return 0;
}
