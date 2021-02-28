/*
 * @Author: your name
 * @Date: 2021-02-27 20:24:33
 * @LastEditTime: 2021-02-28 18:48:48
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /Week_05/比特位计数.cpp
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for (int i = 0; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp[num];
    }
};