
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//

#include <unordered_set>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> pie;
    unordered_set<int> na;
    vector<vector<string>> res;
public:

    bool isVaild(int row, int col) {
        return cols.find(col) == cols.end() && pie.find(row + col) == pie.end() && na.find(row - col) == na.end();
    }

    void dfs(int n, vector<string>& queen, int row) {
        if (row == n) {
            res.push_back(queen);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isVaild(row, col)) {
                queen[row][col] = 'Q';
                cols.insert(col);
                pie.insert(row + col);
                na.insert(row - col);
                dfs(n, queen, row + 1);
                cols.erase(col);
                pie.erase(row + col);
                na.erase(row - col);
                queen[row][col] = '.';
            } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queen(n , string(n, '.'));
        dfs(n, queen, 0);
        return res;

    }
};