class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int sum = 0;
        for(int i=0;i<operations.size();i++){
            
            if(operations[i] == "+" && st.size() >= 2){

                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.push(d1);
                
                int d3 = d1 + d2;
                sum += d3;
            
                st.push(d3);
            }
            else if(operations[i] == "D" && !st.empty()){
                int d1 = st.top();
                d1 = d1*2;
                st.push(d1);
                sum += d1;

            }

            else if(operations[i] == "C"){
                sum -= st.top();
                st.pop();
            }

            else{
                sum += stoi(operations[i]);
                st.push(stoi(operations[i]));
            }
        }
        return sum;

    
    }
};