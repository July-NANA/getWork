#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        char target = ' ';
        string temp = "%20";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == target)
            {
                s.erase(i, 1);
                if (i == 0)
                {
                    s.insert(i, temp);
                }
                else
                {
                    s.insert(i, temp);
                }

                // cout << s[i] << endl;
            }
        }
        string result = s;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution lab;
    string s = "We are happy.";
    string result = lab.replaceSpace(s);
    cout << result << endl;
    return 0;
}
