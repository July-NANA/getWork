#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // int size = 0;
        vector<int> chars(128, 0);     //各字符的个数
        vector<bool> flag(128, false); //各字符是否存在

        //统计t中各字符的情况
        for (int i = 0; i < t.size(); i++)
        {
            flag[t[i]] = true;
            ++chars[t[i]];
        }

        int left = 0, min_left = 0;        //min_left记录前一个左边界
        int cnt = 0;                       //窗口中在t中的字符的个数
        int min_size = s.size() + 1;       //记录前一个窗口大小
        for (int i = 0; i < s.size(); ++i) //i为右边界
        {
            //如果s中的第i个字符在t中存在且在窗口中已经存在的个数不为0
            if (--chars[s[i]] >= 0)
            {
                ++cnt; //窗口中在t中的字符的个数加一（不包括个数超出的）
            }

            //当窗口中包含t中是所有字符
            while (cnt == t.size())
            {
                //如果窗口大小比前一个小则更新左边界和窗口大小
                if (i - left + 1 < min_size)
                {
                    min_left = left;
                    min_size = i - left + 1;
                }

                //碰到下一个是必须包含的元素
                if (flag[s[left]] && ++chars[s[left]] > 0)
                {
                    //窗口中符合条件的字符个数减一
                    --cnt;
                }
                //左边界跳到下一个位置
                ++left;
                /* code */
            }
        }
        string result = s.substr(min_left, min_size);
        //判断窗口大小应小于s的大小
        return min_size > s.size() ? "" : result;
    }
};

int main()
{
    Solution lab;
    string s = "a";
    string t = "aa";
    string result = lab.minWindow(s, t);
    cout << result << endl;
    system("pause");
    return 0;
}
