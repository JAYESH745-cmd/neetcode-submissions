class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<int> time(n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[pos[i]]=speed[i];
        }
        int j=0;
        for(auto i:m){
            time[j++]=(tar-i.first)/i.second;
        }
        for(int i:time) cout<<i<<" ";
        return 3;

    }
};
