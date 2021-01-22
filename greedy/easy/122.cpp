#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int margin = 0;
        int buy = prices[0], sell = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if(i==prices.size()-1){
                margin = sell - buy + margin;
            }else
            {
                /* code */
                buy = min(buy, prices[i]);
                sell = max(sell, prices[i + 1]);
                int a = prices[i], b = prices[i + 1];
                if(prices[i]>prices[i+1]){
                    margin = sell - buy + margin;
                    buy = prices[i + 1];
                    sell = prices[i + 1];
                }
            }
            

            
        }
        return margin;
        }
};

int main(){
    Solution lab;
    vector<int> test = {7,6,4,3,1};
    int re = lab.maxProfit(test);
    return 0;
}
