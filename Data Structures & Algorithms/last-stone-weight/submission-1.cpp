class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int remain = abs(first - pq.top());
            pq.pop();
            if(remain == 0){
                continue;
            }
            else{
                pq.push(remain);
            }
        }

                if(pq.empty()){
            return 0;
        }

        return pq.top();
    }
};
