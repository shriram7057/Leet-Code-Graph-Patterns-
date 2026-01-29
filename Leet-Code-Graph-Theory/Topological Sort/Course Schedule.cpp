class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int taken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            taken++;

            for (int next : graph[course]) {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        return taken == numCourses;
    }
};
