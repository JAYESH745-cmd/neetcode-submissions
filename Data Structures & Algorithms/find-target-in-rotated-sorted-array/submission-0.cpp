class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n=nums.size();
        int l=0,r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==tar) return mid;
            else if(nums[mid]>tar){
                if(nums[l]<tar) r=mid-1;
                else l=mid+1;
            }
            else{
                if(nums[r]>tar) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};
