class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp1,mpp2;
        for(int i=0;i<s1.size();i++){
            mpp1[s1[i]]++;
        }
        int window = s1.size();
        for(int i=0;i<s2.size();i++){
            mpp2[s2[i]]++;

            if(i >= window){
                char ch = s2[i-window];
                mpp2[ch]--;
                if(mpp2[ch] == 0){
                    mpp2.erase(ch);
                }
            }

            if(mpp2 == mpp1)return true;
            
        }
        return false;
    }
};
