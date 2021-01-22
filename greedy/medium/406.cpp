#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool complare(vector<int>& a,vector<int>& b){
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    // static bool complare_1(vector<int>& a,vector<int>& b){
            
    //         return a[0] > b[0];
    // }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // vector<vector<int>> result = people;
        int size = people.size();
        // sort(people.begin(), people.end(), complare_1);
        sort(people.begin(), people.end(), complare);
        
        // vector<vector<int>> result(people.size());
        vector<vector<int>> result;
        people.push_back({0, 0});
        int first = 0, location = 0,dif=0,num=0;
        for (int i = 0; i < size; i++)
        {
            // result[people[i][1]] = people[i];
            int position = people[i][1];
            result.insert(result.begin() + position,people[i]);
            // dif = i - first;
            
            // if(dif<people[i][1]){
                
            //     result.erase(result.begin() + num);
            //     int temp_1 = num + people[i][1]-dif;
            //     result.insert(result.begin() + temp_1 , people[i]);
            //     num--;
            // }
            // if(people[i+1][0]!=people[i][0]){
                
            //     first = i + 1;
            // }
            // num++;
            // if(people[i+1][0]==people[i][0]){
            //     location = i;
            // }
        }
        
        // sort(people.begin(), people.end(), complare);
        
        return result;
    }
};

int main(){
    Solution lab;
    vector<vector<int>> test={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    test = lab.reconstructQueue(test);
    return 0;

}