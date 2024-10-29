/**
 * link: [买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
 */
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = prices[0];
        int end = prices[0];
        int sum = 0;
        for(int i = 1, len = prices.size(); i < len; i++) {
            if(prices[i] > end) {
                end = prices[i];

                int temp = end - start;
                if(temp > sum) {
                    sum = temp;
                }
            } else {
                //出现比之前小价格的值
                if(prices[i] < start) {
                    start = prices[i];
                }
                end = prices[i];
            }
        }

        return sum;
    }
};

int main() {
    vector<int> pirces({10,8,9,5,4,3,2,1});
    // vector<int> pirces({10,2,10,4,25});
    Solution s;
    std::cout << s.maxProfit(pirces) << std::endl;
    
    return 0;
}