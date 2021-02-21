
// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
// 
// 你可以对一个单词进行如下三种操作：
// 
//     插入一个字符
//     删除一个字符
//     替换一个字符
// 
// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

// dp[i][j] : 表示 word1[0..i)转为word2[0..j) 的最小次数
// word1[i - 1] == word2[j - 1]: dp[i][j] = dp[i - 1][j - 1]
// word1[i - 1] != word2[j - 1]:
// 改： dp[i][j] = dp[i - 1][j - 1] + 1
// word1增： dp[i][j] = dp[i - 1][j] + 1
// word2增： dp[i][j] = dp[i][j - 1] + 1
// 选3种策略的最小值
// word1 为空 ：dp[0][i] = i
// word2 为空 : dp[i][0] = i

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));  

        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] != word2[j - 1]) {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }

            } 
        }
        return dp[m][n];


    }
};
