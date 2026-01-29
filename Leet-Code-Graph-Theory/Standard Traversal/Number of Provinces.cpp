class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int next = 0; next < isConnected.size(); next++) {
            if (isConnected[city][next] == 1 && !visited[next]) {
                dfs(next, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};
