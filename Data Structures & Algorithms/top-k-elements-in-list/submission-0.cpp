class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();

        for(int i:nums){
            m[i]++;
        }
        vector<int> ans;
        for(auto i:m){
            if(i.second>=k) ans.push_back(i.first);
        }
        return ans;
    }
};
