// dfs
class Solution_1 {
public:
    bool isVaild(vector<vector<char>>& grid, int row, int col) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    // dfs
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (!isVaild(grid, row, col) || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '0';
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

// bfs
class Solution_2 {
public:
    void bfs(vector<vector<char>>& grid, int row, int col) {
        vector<int> offset = {0, 1, 0 , -1, 0};
        queue<pair<int, int>> que;
        que.push({row, col});
        
        while (!que.empty()) {
            auto pos = que.front();
            row = pos.first;
            col = pos.second;
            que.pop();
            
            for (int i = 0; i < offset.size() - 1; i++) {
                int dx = row + offset[i];
                int dy = col + offset[i + 1];
                if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size()
                    && grid[dx][dy] == '1') {
                        que.push({dx, dy});
                        grid[dx][dy] = '0';
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};


