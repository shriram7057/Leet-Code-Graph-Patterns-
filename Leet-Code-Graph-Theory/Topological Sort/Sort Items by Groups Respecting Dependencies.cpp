class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;
        vector<int> res;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            for (int v : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return res.size() == n ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Step 1: Assign unique groups to -1 items
        int gid = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = gid++;
        }

        // Graphs
        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);

        vector<vector<int>> groupGraph(gid);
        vector<int> groupIndegree(gid, 0);

        // Step 2: Build graphs
        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                if (group[prev] != group[i]) {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Step 3: Topo sort
        vector<int> itemOrder = topoSort(n, itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(gid, groupGraph, groupIndegree);

        if (itemOrder.empty() || groupOrder.empty())
            return {};

        // Step 4: Collect items per group
        unordered_map<int, vector<int>> groupItems;
        for (int item : itemOrder)
            groupItems[group[item]].push_back(item);

        // Step 5: Build answer
        vector<int> result;
        for (int g : groupOrder) {
            for (int item : groupItems[g])
                result.push_back(item);
        }

        return result;
    }
};
