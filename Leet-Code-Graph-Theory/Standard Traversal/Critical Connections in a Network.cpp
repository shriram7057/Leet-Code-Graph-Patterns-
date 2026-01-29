class Solution {
public:
    vector<vector<int>> graph;
    vector<int> disc, low;
    vector<vector<int>> bridges;
    int time = 0;

    void dfs(int u, int parent) {
        disc[u] = low[u] = time++;

        for (int v : graph[u]) {
            if (v == parent) continue;

            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        disc.assign(n, -1);
        low.assign(n, -1);

        for (auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(0, -1); // graph is connected

        return bridges;
    }
};
