class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        string res = "";
        for(auto &it : mpp){
            if (it.second > (n + 1) / 2)
                return "";
            pq.push({it.second,it.first});
        }

        while(!pq.empty()){
            auto [cnt,ch] = pq.top();
            pq.pop();

            if(!res.empty() && res.back() == ch){
                auto [cnt1,ch1] = pq.top();
                pq.pop();
                res += ch1;
                cnt1--;
                if(cnt1>0){
                    pq.push({cnt1,ch1});
                }
                pq.push({cnt,ch});
            }
            else{
                res+= ch;
                cnt--;
                if(cnt>0){
                    pq.push({cnt,ch});
                }
            }
        }
        return res;
    }
};