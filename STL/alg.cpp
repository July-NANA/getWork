#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    //求和
    int sum = accumulate(v.begin(), v.end(), 0);

    return 0;
}
