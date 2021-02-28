class Solution {
public:
    bitset<9> findEmptySet(int i, int j) {
        return ~(rows[i] | cols[j] | boxes[i / 3 * 3 + j / 3]);
    }
    vector<int> findMinEmptyPos(vector<vector<char>>& board) {
        int minCount = 10;
        vector<int> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                auto emptySet = findEmptySet(i, j);
                if (emptySet.count() < minCount) {
                    minCount = emptySet.count();
                    ans = {i, j};
                }
            }
        }
        return ans;
    }
    bool dfs(vector<vector<char>>& board, int space) {
        if (space == 0) {
            return true;
        }
        vector<int> emptyPos = findMinEmptyPos(board);
        int row = emptyPos[0];
        int col = emptyPos[1];
        int box = row / 3 * 3 + col / 3;

        auto emptySet = findEmptySet(row, col);
        for (int i = 0; i < emptySet.size(); i++) {
            if (!emptySet.test(i)) {continue;}
            board[row][col] = i + '1';
            rows[row][i] = cols[col][i] = boxes[box][i] = 1;
            if (dfs(board, space - 1)) {
                return true;
            }
            rows[row][i] = cols[col][i] = boxes[box][i] = 0;
            board[row][col] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>> (9, bitset<9>());
        cols = vector<bitset<9>> (9, bitset<9>());
        boxes = vector<bitset<9>> (9, bitset<9>());
        int space = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    space++;
                } else {
                    int n = board[i][j] - '1';
                    rows[i][n] = cols[j][n] = boxes[i/ 3 * 3 + j / 3][n] = 1;
                }
            }
        }
        dfs(board, space);
    }
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<bitset<9>> boxes;
};