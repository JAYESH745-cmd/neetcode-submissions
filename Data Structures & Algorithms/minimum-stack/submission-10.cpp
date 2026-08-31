class MinStack {
public:
    MinStack() { 
            
    }
    stack<int> st;
    stack<int> minstack;
    int mini=INT_MAX;
    
    void push(int val) {
        st.push(val);
        if(val<=mini) {
            mini=val;
            minstack.push(val);
        }
    }
    
    void pop() {
        if(st.size()){
            if(st.top()==minstack.top()){
                st.pop();
                minstack.pop();
                if(minstack.size()) mini=minstack.top();
                else mini=INT_MAX;
            }
            else st.pop();
        }
        
    }
    
    int top() {
        if(st.size()) return st.top();
        return -1;
    }
    
    int getMin() {
        if(minstack.size()) return minstack.top();
        return -1;
    }
};
