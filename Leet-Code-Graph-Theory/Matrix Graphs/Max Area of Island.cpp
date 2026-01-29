class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;  // mark visited
        int area = 1;

        area += dfs(grid, r + 1, c);
        area += dfs(grid, r - 1, c);
        area += dfs(grid, r, c + 1);
        area += dfs(grid, r, c - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};
