class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int,int>>>& graph) {
        int changes = 0;

        for (auto& [next, cost] : graph[node]) {
            if (next == parent) continue;
            changes += cost;
            changes += dfs(next, node, graph);
        }

        return changes;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto& c : connections) {
            int a = c[0], b = c[1];
            graph[a].push_back({b, 1}); // original direction, needs change
            graph[b].push_back({a, 0}); // reverse direction, already fine
        }

        return dfs(0, -1, graph);
    }
};
