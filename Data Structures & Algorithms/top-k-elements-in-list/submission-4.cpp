class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();

        for(int i:nums){
            m[i]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i:m){
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
