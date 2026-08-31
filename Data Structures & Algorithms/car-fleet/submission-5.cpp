class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<double> time(n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[pos[i]]=speed[i];
        }
        int j=0;
        for(auto i:m){
            time[j++]=(double)(tar-i.first)/i.second;
        }
        
        for(double i :time ){
            cout<<i<<" ";
        }
        stack<double> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty() || st.top()<time[i]){
                st.push(time[i]);
            }
        }
        if(!st.size()) return 1;
        return st.size();
    }
};
