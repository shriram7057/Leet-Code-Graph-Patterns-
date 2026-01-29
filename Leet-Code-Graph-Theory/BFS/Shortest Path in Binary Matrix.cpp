class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Edge cases
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // 8 directions (including diagonals)
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // mark visited
        int pathLen = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                // Reached destination
                if (r == n - 1 && c == n - 1)
                    return pathLen;

                for (auto& d : dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1; // mark visited
                        q.push({nr, nc});
                    }
                }
            }

            pathLen++;
        }

        return -1;
    }
};
