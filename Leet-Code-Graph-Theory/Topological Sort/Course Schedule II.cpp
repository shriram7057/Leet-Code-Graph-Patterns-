class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int next : graph[course]) {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        // If cycle exists
        if (order.size() != numCourses)
            return {};

        return order;
    }
};
