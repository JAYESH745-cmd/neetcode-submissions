class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int m=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else {
                m=min(m,nums[mid]);
                r=mid-1;
            } 
        }
        return m;
    }
};
