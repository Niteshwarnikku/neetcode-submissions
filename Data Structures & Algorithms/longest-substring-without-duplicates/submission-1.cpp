class Solution {
public:
    int max(int a,int b){
        if(a>b)return a;
        return b;
    }
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int res = 0;
        int j=0;
        for(int i=0;i<s.size();i++){
            
            while (st.find(s[i]) != st.end()) {
            st.erase(s[j]);
            j++;
        }

        st.insert(s[i]);
        res = max(res, i - j + 1);
        }
        return res;
    }
};
