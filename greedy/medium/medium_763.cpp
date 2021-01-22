#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        int start[26] = {0};
        int end[26] = {0};
        char alp[26] = {'a'};
        for (int i = 0; i < 26; i++)
        {
            alp[i] = 'a' + i;
        }
        
        for (int i = 0; i < 26; i++)
        {
            /* code */
            // start[i] = S.find(alp[i]);
            end[i] = S.rfind(alp[i]);
            // end[S[i] - 'a'] = i;
        }
        int right = 0,left=0;

        for (int i = 0; i < S.size(); i++)
        {
            /* code */
            char c = S[i];
            int num = end[S[i] - 'a'];
            right = max(right, end[S[i] - 'a']);
            if(right==i){
                result.push_back(right - left + 1);
                left = i + 1;
            }

            // if(right<end[S[i]-'a']){
            //     right = end[S[i] - 'a'];
            // }
            
        }
        
        return result;
    }
};

int main(){
    Solution lab;
    string test = "vhaagbqkaq";
    vector<int> result = lab.partitionLabels(test);
    return 0;
}
