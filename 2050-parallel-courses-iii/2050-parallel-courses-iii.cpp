class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build the directed graph and calculate in-degrees
        for (const auto& relation : relations) {
            int prevCourse = relation[0] - 1;
            int nextCourse = relation[1] - 1;
            graph[prevCourse].push_back(nextCourse);
            inDegree[nextCourse]++;
        }

        queue<int> q;
        vector<int> courseTime(n, 0);

        // Initialize the queue with courses that have no prerequisites
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int minTime = 0;

        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();

            // Update the time needed for the current course
            courseTime[currCourse] += time[currCourse];
            minTime = max(minTime, courseTime[currCourse]);

            // Process the next courses
            for (int nextCourse : graph[currCourse]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
                courseTime[nextCourse] = max(courseTime[nextCourse], courseTime[currCourse]);
            }
        }

        return minTime;
    }
};
