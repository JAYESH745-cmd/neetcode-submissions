class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();

        for(int i:nums){
            m[i]++;
        }
        vector<int> ans;
        int j=m.size();
        int u=0;
        for(auto i:m){
            if(u>=j-k) ans.push_back(i.first);
            u++;
        }
        return ans;
    }
};
