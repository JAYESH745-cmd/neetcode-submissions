class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);

        
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && h[st.top()]>=h[i]) st.pop();
            if(st.size()) nse[i]=st.top();
            st.push(i);
        }
        st={};
        for(int i=0;i<n;i++){
            while(st.size() && h[st.top()]>h[i]) st.pop();
            if(st.size()) pse[i]=st.top();
            st.push(i);
        }

        
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,(nse[i]-pse[i]-1)*h[i]);
        }
        return area;
    }
};
