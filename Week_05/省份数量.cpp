//
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
// 
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
// 
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
// 
// 返回矩阵中 省份 的数量。
//
//
// 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// 输出：2
// 
// 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// 输出：3
// 
// 解法：dfs/bfs/并查集
//
//
//
//
// dfs
class Solution_1 {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& isConnected) {
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(j, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        if (size == 0) {
            return 0;
        }
        vector<bool> visited(size, false);
        int count = 0;

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, isConnected);
            }
        }
        return count;
    }
};

// bfs
class Solution_2 {
public:
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        queue<int> que;
        que.push(i);
        visited[i] = true;
        while (!que.empty()) {
            int row = que.front();
            que.pop();
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[row][j] == 1 && !visited[j]) {
                    que.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        if (size == 0) {
            return 0;
        }
        vector<bool> visited(size, false);
        int count = 0;
        for (int  i = 0; i < size; i++) {
            if (!visited[i]) {
                count++;
                bfs(isConnected, visited, i);
            }
        }
        return count;
    }
};

//  并查集
class Solution_3 {
public:
    class Unionfind {
    public:
        Unionfind(int size) {
            capacity = size;
            parent.resize(capacity);
            for (int i = 0; i < capacity; i++) {
                parent[i] = i;
            }
        }
        int Find(int x) {
            int root = x;
            while (root != parent[root]) {
                root = parent[root];
            }
            return root;
        }
        int IsConnected(int x, int y) {
            return Find(x) == Find(y);
        }
        void Union(int x, int y) {
            int root_x = Find(x);
            int root_y = Find(y);
            parent[root_x] = root_y;
        }
        int Size() {
            int sz = 0;
            for (int i = 0; i < capacity; i++) {
                if (parent[i] == i) {
                    sz++;
                }
            }
            return sz;
        }
    private:
        vector<int> parent;
        int capacity;
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        if (size == 0) {
            return 0;
        }

        Unionfind uf(size);
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (isConnected[i][j] == 1) {
                    uf.Union(i, j);
                }
            }
        }

        return uf.Size();

    }
};