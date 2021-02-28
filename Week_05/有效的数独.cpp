// 需要每行，每列，每个boxes判重
// box_index = (row / 3) * 3 + col / 3;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int sz = board.size();
        vector<vector<int>> rows(sz, vector<int>(sz));
        vector<vector<int>> cols(sz, vector<int>(sz));
        vector<vector<int>> boxes(sz, vector<int>(sz));

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (boxes[i][j] == '.') {
                    int n = board[i][j] - '0';
                    int index = (i / 3) * 3 + j / 3;
                    if (rows[i][n] == 1 || cols[j][n] == 1 || boxes[index][n] == 1) {
                        return false;
                    }
                    rows[i][n] = cols[j][n] = boxes[index][n] = 1;
                }
            }
        }
        return true;
    }
};
