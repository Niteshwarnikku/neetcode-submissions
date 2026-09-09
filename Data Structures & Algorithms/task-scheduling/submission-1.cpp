class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // step 1 put all task in map with their frequecny
        map<char,int>mpp;
        for(auto task : tasks){
            mpp[task]++;
        }

        // step 2 put all frequecy of task in maxHeap
        priority_queue<int>pq;
        for(auto& it : mpp){
            pq.push(it.second);
        }

        int time = 0;
        // step 3 process the task in cycle of size(n+1);
        
        while(!pq.empty()){
            vector<int>temp;
            int cycle = n +1;
            int i=0;

            while(i<cycle && !pq.empty()){
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if(cnt > 0){
                    temp.push_back(cnt);
                }
                time++;
                i++;
            }

            // step 4 put all remain tasks in queue

            for(int val : temp){
                pq.push(val);
            }
            // if pq is empty no need to calculate idle time
            if(pq.empty()){
                break;
            }

            time += cycle-i;
        }
        return time;
    }
};
