
// 
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//
// 此外，你可以假设该网格的四条边均被水包围。
// 
// 示例 1：
// 输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
// ]
// 输出：1

#include <vector>
using namespace std;

class Solution {
public:
    bool ingrid(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& pos, int x, int y) {
        if (!ingrid(grid, x, y) || grid[x][y] != '1') {
            return;
        }

        grid[x][y] = '0';
        for (int i = 0; i < pos.size(); i++) {
            int temp_x = x + pos[i][0];
            int temp_y = y + pos[i][1];
            if (ingrid(grid, temp_x, temp_y) && grid[temp_x][temp_y] == '1') {
                dfs(grid, pos, temp_x, temp_y);
            }  
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> pos{
            {0, 1}, {0, -1},
            {1, 0}, {-1, 0},
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, pos, i, j);
                }
            }
        }
        return count;

    }
};