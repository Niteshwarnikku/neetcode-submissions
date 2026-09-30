class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Add original index
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }

        // Sort by enqueue time
        sort(tasks.begin(), tasks.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> res;

        int i = 0;
        long long time = 0;

        while (i < n || !pq.empty()) {

            // Add all available tasks
            while (i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // No task is currently available
            if (pq.empty()) {
                time = tasks[i][0];
            }
            else {
                auto [processingTime, index] = pq.top();
                pq.pop();

                time += processingTime;
                res.push_back(index);
            }
        }

        return res;
    }
};