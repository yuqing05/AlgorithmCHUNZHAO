
// 给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

// 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

//     如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
//     如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
//     如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
//     如果在此次点击中，若无更多方块可被揭露，则返回面板。
#include <vector>
using namespace std;

class Solution {
public:
    bool inboard(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<int>>& move, int x, int y) {
        if (!inboard(board, x, y) || board[x][y] != 'E') {
            return;
        }
        int marinCount = 0;
        for (int i = 0; i < 8; i++) {
            int temp_x = x + move[i][0];
            int temp_y = y + move[i][1];
            if (inboard(board, temp_x, temp_y) && board[temp_x][temp_y] == 'M') {
                marinCount++;
            }
        }
        if (marinCount > 0) {
            board[x][y] = marinCount + '0';
        } else {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i++) {      
                dfs(board, move, x + move[i][0], y + move[i][1]);
            }
        }
    }
    
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<int>> move = { 
            {0, 1}, {0, -1},
            {1, 1}, {1, 0}, {1, -1},
            {-1, 1}, {-1, 0}, {-1, -1},
        };
        if (!inboard(board, click[0], click[1])) {
            return board;
        }
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, move, click[0], click[1]);
        return board;
	}

};