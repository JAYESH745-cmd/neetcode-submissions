class MinStack {
public:
    MinStack() {
        
    }
    stack<int> st;
    int m=INT_MAX;
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            m=val;
        }
        else if(m>val){
            int c=val+(val-m);
            st.push(c);
            m=val;
        }
        else st.push(val);
    }
    
    void pop() {
        if(st.size() && st.top()<m){
            m=m+(m-st.top());
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.size()) {
            if(st.top()<m) return m;
            return st.top();
        }
    }
    
    int getMin() {
        return m;
    }
};
