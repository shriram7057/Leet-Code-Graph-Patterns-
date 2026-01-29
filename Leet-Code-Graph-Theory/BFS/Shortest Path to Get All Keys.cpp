class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startR, startC;
        int keyCount = 0;

        // Find start and count keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    keyCount++;
                }
            }
        }

        int allKeysMask = (1 << keyCount) - 1;

        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(1 << keyCount, false))
        );

        q.push({startR, startC, 0});
        visited[startR][startC][0] = true;

        vector<int> dirs = {0, 1, 0, -1, 0};
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, mask] = q.front();
                q.pop();

                if (mask == allKeysMask)
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d];
                    int nc = c + dirs[d + 1];
                    int newMask = mask;

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    char cell = grid[nr][nc];
                    if (cell == '#') continue;

                    // Lock
                    if (cell >= 'A' && cell <= 'F') {
                        int keyBit = cell - 'A';
                        if (!(mask & (1 << keyBit)))
                            continue;
                    }

                    // Key
                    if (cell >= 'a' && cell <= 'f') {
                        int keyBit = cell - 'a';
                        newMask |= (1 << keyBit);
                    }

                    if (!visited[nr][nc][newMask]) {
                        visited[nr][nc][newMask] = true;
                        q.push({nr, nc, newMask});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
