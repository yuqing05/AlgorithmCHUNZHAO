class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> left;
    unordered_set<int> right;
    bool isInBoard(int row, int col) {
        return cols.count(col) || left.count(row + col) || right.count(row - col);
    }
public:
    void dfs(int n, int row, int& ans) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isInBoard(row, col)) {
                continue;
            }
            cols.insert(col);
            left.insert(row + col);
            right.insert(row - col);
            dfs(n, row + 1, ans);
            cols.erase(col);
            left.erase(row + col);
            right.erase(row - col);
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        dfs(n, 0, ans);
        return ans;
    }
};
class Solution {
public:
    void dfs(int n, int row, int& ans, short cols, short pie, short na) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (((1 << col) & cols) || ((1 << (row + col)) & pie) || ((1 << (row - col + n - 1)) & na)) {
                continue;
            }
            dfs(n, row+1, ans, cols | (1 << col), pie | (1 << (row + col)),na | (1 << (row - col + n - 1)));
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        dfs(n, 0, ans, 0, 0, 0);
        return ans;
    }
};