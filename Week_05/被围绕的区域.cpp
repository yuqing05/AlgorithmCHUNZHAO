// dfs
class Solution {
public:
    bool isinboard(vector<vector<char>>& board, int row, int col) {
        return row < board.size() &&  row >= 0 && col >= 0 && col < board[0].size();
    }
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (!isinboard(board, row, col) && board[row][col] != 'O') {
            return;
        }
        vector<int> offset = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4;i++) {
            if (isinboard(board, offset[i] + row, col + offset[i + 1])
               && board[row + offset[i]][col + offset[i + 1]] == 'O') {
                   board[row + offset[i]][col + offset[i + 1]] = '#';
                   dfs(board, row + offset[i], col + offset[i + 1]);
               }
        }

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O'
                    && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                    board[i][j] = '#';
                    dfs(board, i, j);

                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        return;

    }
};
// bfs
class Solution {
public:
    bool isinboard(vector<vector<char>>& board, int row, int col) {
        return row < board.size() &&  row >= 0 && col >= 0 && col < board[0].size();
    }
    void bfs(vector<vector<char>>& board, int row, int col) {
        queue<pair<int, int>> que;
        que.push({row, col});
        vector<int> offset = {0, 1, 0, -1, 0};
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            row = it.first;
            col = it.second;
            for (int i = 0; i < 4; i++) {
                if (isinboard(board, offset[i] + row, offset[i + 1]+ col)
                && board[row + offset[i]][col + offset[i + 1]] == 'O') {
                    que.push({row + offset[i], col + offset[i + 1]});
                    board[row + offset[i]][col + offset[i + 1]] = '#';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O'
                    && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                    board[i][j] = '#';
                    bfs(board, i, j);

                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        return;

    }
};

