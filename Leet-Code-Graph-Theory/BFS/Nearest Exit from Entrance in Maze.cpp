class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        
        maze[entrance[0]][entrance[1]] = '+'; // mark visited
        int steps = 0;

        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            int size = q.size();
            steps++;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dirs[i];
                    int nc = c + dirs[i + 1];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n || maze[nr][nc] == '+')
                        continue;

                    // Check exit condition
                    if (nr == 0 || nc == 0 || nr == m - 1 || nc == n - 1)
                        return steps;

                    maze[nr][nc] = '+'; // mark visited
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};
