class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> m;
        

        for(int i=0;i<n;i++){
            int tar=target-nums[i];
            if(m.find(tar)!=m.end()) return {m[tar],i};
            else m[nums[i]]=i;
        }
    }
};
