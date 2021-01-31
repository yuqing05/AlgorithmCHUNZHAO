/*
 * @Description: 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * @FilePath: https://leetcode-cn.com/problems/combinations/
 */
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    void dfs(int index, int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = index; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(i + 1, n, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (n < 1 || n < k) {
            return {{}};
        }
        dfs(1, n ,k);
        return res;
    }
};