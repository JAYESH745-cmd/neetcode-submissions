class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(k>j){
                if(nums[i]+nums[j]+nums[k]==0) {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0) j++;
                else k--;;
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};
//-4 -1 -1 0 1 2