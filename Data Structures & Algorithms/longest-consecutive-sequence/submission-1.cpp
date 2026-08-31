class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if (n==1) return 1;
        int i=0,j=1;
        int dup=0;
        int count=0;
        while(j<n){
            if(nums[i]==nums[j]) dup++;
            else if(nums[j]-nums[i]==1){
                count++;
            } 
            i++;j++;
            count=max(count,j-i+1-dup);
        }
        return count;
    }
};
// 2 3 4 5 10 20
