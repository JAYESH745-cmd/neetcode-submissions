class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2,vector<int>& nums){
        int i=0,j=0,k=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                nums[k++]=nums1[i++];
            }
            else nums[k++]=nums2[j++];
        }
        while(i<n){
            nums[k++]=nums1[i++];
        }
        while(j<m){
            nums[k++]=nums2[j++];
        }
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> nums(n+m);
        merge(nums1,nums2,nums);
        for(int i :nums){
            cout<<i<<" ";
        }
        int k=nums.size();
        if(k%2==0) return (double) nums[k/2]+nums[k/2-1];
        else return (double) nums[k/2];
    }
};
