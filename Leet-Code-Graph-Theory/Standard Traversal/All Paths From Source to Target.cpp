class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(int node, vector<vector<int>>& graph) {
        path.push_back(node);

        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            for (int next : graph[node]) {
                dfs(next, graph);
            }
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return result;
    }
};
