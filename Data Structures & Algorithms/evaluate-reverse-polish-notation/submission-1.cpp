class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" && st.size() >= 2){
                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.pop();
                int sum = d1 + d2;
                st.push(sum);
            }
            else if(tokens[i] == "-" && st.size() >= 2){
                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.pop();
                int sub = d2 - d1;
                st.push(sub);
            }
            else if(tokens[i] == "*" && st.size() >= 2){
                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.pop();
                int mul = d1 * d2;
                st.push(mul);
            }
            else if(tokens[i] == "/" && st.size() >= 2){
                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.pop();
                int div = d2/d1;
                st.push(div);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
