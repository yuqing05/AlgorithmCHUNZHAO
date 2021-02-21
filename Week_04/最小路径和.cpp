// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 
// 说明：每次只能向下或者向右移动一步。
// 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
// 输出：7
// 解释：因为路径 1→3→1→1→1 的总和最小。
class Solution {
public:
    // 二维dp
    // 初始化：dp[0][0] = grid[0][0];
    // dp方程：
    // i == 0 : dp[0][j] = dp[0][j - 1] + grid[i][j]
    // j == 0 : dp[i][0] = dp[i - 1][0] + grid[i][j]
    // 其他 : dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])
    // retuen  : dp[m - 1][n - 1]
    // 一维dp: i 行 j 列
    // 初始化: dp[0] = dp[0] + grid[i][0] 
    // dp方程：j > 0 : dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]
    // return : dp[n - 1]
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);

        for (int i = 0; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                if (i == 0) {a
                    dp[j] = dp[j - 1] + grid[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
                
        }
        return dp[n - 1];
    }
};