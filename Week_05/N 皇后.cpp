// dfs
class Solution {
private:
   unordered_set<int> cols;
   unordered_set<int> pie;
   unordered_set<int> na; 
   vector<vector<string>> result;
  
public:
    void dfs(int row, int n, vector<string> &path) {
        if (row == n) {
            result.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || pie.count(row + col) || na.count(row - col)) {
                continue;
            }
            path[row][col] = 'Q';
            cols.insert(col);
            pie.insert(col + row);
            na.insert(row - col);
            dfs(row + 1, n, path);
            path[row][col] = '.';
            cols.erase(col);
            pie.erase(row + col);
            na.erase(row - col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        dfs(0, n, path);
        return result;
    }
};
// 空间优化
// 因为是由上到下，且是passed by value 所有可以省略 改回原来值的操作
// row - col 会小于0 得给他们找到能放并且不冲突的地方  row - col + n - 1
class Solution {
private: 
   vector<vector<string>> result;
public:
    void dfs(int row, int n, vector<string> &path, uint32_t cols, uint32_t pie, uint32_t na) {
        if (row == n) {
            result.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (((1 << col) & cols) || ((1 << (row + col) & pie)) || (1 << (n - 1 + row - col) & na)) {
                continue;
            }
            path[row][col] = 'Q';
            dfs(row + 1, n, path, cols|( 1 << col), pie|(1 << (row + col)), na|(1 << (row - col + n -1)));
            path[row][col] = '.';

            
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        dfs(0, n, path, 0, 0, 0);
        return result;
    }
};