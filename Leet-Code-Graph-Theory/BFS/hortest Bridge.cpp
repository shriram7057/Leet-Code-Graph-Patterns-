class Solution {
public:
    int n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> q;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = 2;          // mark visited
        q.push({i, j});          // add to BFS queue

        for (auto& d : dirs)
            dfs(i + d[0], j + d[1], grid);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool found = false;

        // 1️⃣ Find first island
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true;
                }
            }
        }

        // 2️⃣ BFS to reach second island
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;

                    if (grid[nx][ny] == 1)
                        return steps;   // reached second island

                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
