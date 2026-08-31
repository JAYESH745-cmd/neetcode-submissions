class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<int> st;
        for(char i :s){
            if(i=='{' || i=='[' || i=='(') st.push(i);
            else if(st.size() && i==']') {
                if(st.top()!='[') return false;
                else st.pop();
            }
            else if(st.size() && i==')') {
                if(st.top()!='(') return false;
                else st.pop();
            }
            else if(st.size() && i=='}') {
                if(st.top()!='{') return false;
                else st.pop();
            }
        }
        if(st.size()) return false;
        return true;
    }
};
