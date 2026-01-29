class Solution {
public:
    int dfs(int node, vector<vector<int>>& tree, vector<int>& informTime) {
        int maxSubTime = 0;
        for (int sub : tree[node]) {
            maxSubTime = max(maxSubTime, dfs(sub, tree, informTime));
        }
        return informTime[node] + maxSubTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n);

        // Build manager -> subordinates tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i);
            }
        }

        return dfs(headID, tree, informTime);
    }
};
