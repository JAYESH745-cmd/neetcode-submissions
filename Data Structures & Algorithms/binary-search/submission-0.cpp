class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(right>left){
            int mid=right+(left-right)/2;
            if(nums[mid]==tar) return mid;
            else if(tar>nums[mid]) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};
