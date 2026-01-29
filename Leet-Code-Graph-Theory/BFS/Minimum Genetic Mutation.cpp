class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, start, visited);
    }

private:
    bool dfs(vector<int>& arr, int i, vector<bool>& visited) {
        // Out of bounds or already visited
        if (i < 0 || i >= arr.size() || visited[i]) {
            return false;
        }

        // Found a zero
        if (arr[i] == 0) {
            return true;
        }

        visited[i] = true;

        // Try both possible jumps
        return dfs(arr, i + arr[i], visited) ||
               dfs(arr, i - arr[i], visited);
    }
};
