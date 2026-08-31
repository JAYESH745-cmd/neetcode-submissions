class MinStack {
public:
    MinStack() {
        
    }
    stack<long long> st;
    long long m=INT_MAX;
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            m=val;
        }
        else if(m>val){
            long long c=val+(val-m);
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
    
    long long top() {
        if(st.size()) {
            if(st.top()<m) return m;
            return st.top();
        }
    }
    
    long long getMin() {
        return m;
    }
};
