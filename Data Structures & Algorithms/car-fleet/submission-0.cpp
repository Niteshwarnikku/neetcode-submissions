class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         vector<pair<int,int>>temp;
        vector<double>st;

        for(int i=0;i<position.size();i++){
            temp.push_back({position[i],speed[i]});
        }
        sort(temp.rbegin(),temp.rend());

        for(auto it : temp){
            st.push_back(double(target-it.first)/it.second);
            if(st.size() >= 2 && st.back() <= st[st.size()-2]){
                st.pop_back();
            }

        }
        return st.size();
    }
};
