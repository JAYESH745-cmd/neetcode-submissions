class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string i:tokens){
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                if(i=="+") st.push(val1+val2);
                else if(i=="-") st.push(val2-val1);
                else if(i=="*") st.push(val1*val2);
                else st.push(val2/val1);
            }
            else st.push(stoi(i));
        }
        return st.top();
    }
};
