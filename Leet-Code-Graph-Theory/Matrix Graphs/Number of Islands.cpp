class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // boundary + water check
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
            return;
        
        // mark current land as visited
        grid[r][c] = '0';
        
        // explore all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        int islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};
