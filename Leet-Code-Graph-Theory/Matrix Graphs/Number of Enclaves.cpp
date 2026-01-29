class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return;
        
        grid[r][c] = 0;  // remove land
        
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // 1️⃣ Remove all land connected to boundaries
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        
        // 2️⃣ Count remaining land cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};
