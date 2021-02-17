#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> output;
    vector<int> printNumbers(int n)
    {
        if (n <= 0)
        {
            return vector<int>(0);
        }
        string s(n, '0');
        for (int i = 0; i <= 9; i++)
        {
            s[0] = i + '0';
            permutation(s, n, 1);
        }
        return output;
    }
    void permutation(string &s, int length, int pos)
    {
        if (pos == length)
        {
            inputNumbers(s);
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            s[pos] = i + '0';
            permutation(s, length, pos + 1);
        }
    }
    void inputNumbers(string &s)
    {
        bool isUnwantedZero = true;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isUnwantedZero && s[i] != '0')
            {
                /* code */
                isUnwantedZero = false;
            }
            if (!isUnwantedZero)
            {
                temp += s[i];
            }
        }
        if (temp != "")
        {
            output.push_back(stoi(temp));
        }
    }
};