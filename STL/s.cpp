#include <bits/stdc++.h>
using namespace std;

void output(string::iterator &s)
{
    // s += 2;
    // cout << (*s + 1) << endl; //结果为98
    // cout << *(s + 1) << endl; //结果为b
    cout << *s << endl; //输出a
    // ++s;
    // cout << *s << endl; //输出b
    // if ((*s) == '\0')
    // {
    //     cout << 1 << endl;
    // }
}

int main(int argc, char const *argv[])
{
    string s = "abcdefg";
    string::iterator st = s.begin();
    cout << *st << endl;
    output(st += 2);
    return 0;
}
