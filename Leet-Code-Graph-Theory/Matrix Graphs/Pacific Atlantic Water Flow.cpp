class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;

        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            if (ocean[nr][nc])
                continue;
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row + left column
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, pacific);
        for (int j = 0; j < n; j++)
            dfs(0, j, heights, pacific);

        // Atlantic: bottom row + right column
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlantic);
        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlantic);

        // Cells reachable by both
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
