#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    static bool complare (vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        int num = 1;//弓箭数量
        sort(points.begin(), points.end(),complare);
        int border = points[0][1];
        // int border = 0;
        int size = points.size();
        for (int i = 0; i < size; i++)
        {   
            /* code */
            if(points[i][0]>border){
                num++;
                border = points[i][1];
            }
        }
        return num;
    
    }
};

int main(){
    Solution lab;
    // vector<vector<int>> test{{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> test{{-10,16}};
    int n = 1;
    int re = lab.findMinArrowShots(test);
    cout << re << endl;
    return 0;
}