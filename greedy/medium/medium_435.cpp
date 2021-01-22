#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool complare (vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        int first = 0, last = 0;
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), complare);
        int total = 0, pre = intervals[0][1];
        for (int i = 1; i < size; i++)
        {
            /* code */
            if(intervals[i][0]<pre){
                total++;
            }else
            {
                pre = intervals[i][1];
            }
            
        }
        
        return total;

    }

};

int main()
{
    Solution lab;
    vector<vector<int>> test{{ 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 }};
    int n=lab.eraseOverlapIntervals(test);
    // vector<int> a = test[1], b = test[2];
    // cout << a[0] << "," << a[1] << endl;
    // cout << b[0] << "," << b[1] << endl;
    //cout << test[0][0];
    return 0;
}