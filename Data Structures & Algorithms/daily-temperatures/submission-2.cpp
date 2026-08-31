class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n =temp.size();
        stack<int> st;
        vector<int> nse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(st.size() && temp[st.top()]<=temp[i]) st.pop();
            if(st.size()) nse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nse[i]==-1) nse[i]=0;
            else nse[i]=nse[i]-i;
        }
        return nse;
    }
};
