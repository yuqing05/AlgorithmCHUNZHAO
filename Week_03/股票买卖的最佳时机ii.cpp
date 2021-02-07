// 定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

#include <vector>
using namespace std;

class Solution {
public:
    // dp[i][0]:第i天不持有股票的最佳收益， dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
    // dp[i][1]:第i天持有股票的最佳收益, dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[0])
    // 初始化: dp[0][0] = 0; dp[0][1] = -prices[0];
    // n天后，最佳股票收益是 dp[n - 1][0]
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 1) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};