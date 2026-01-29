class Solution {
public:
    // 0 = unvisited, 1 = visiting, 2 = safe
    vector<int> state;

    bool dfs(int node, vector<vector<int>>& graph) {
        if (state[node] != 0) {
            // If visiting -> cycle -> unsafe
            return state[node] == 2;
        }

        state[node] = 1; // mark as visiting

        for (int next : graph[node]) {
            if (!dfs(next, graph)) {
                return false; // leads to cycle
            }
        }

        state[node] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.assign(n, 0);
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
