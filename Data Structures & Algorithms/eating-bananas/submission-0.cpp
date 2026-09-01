class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=INT_MIN;
        for (int i:piles){
            mx=max(i,mx);
        }
        int r=mx,l=1;
        int ans=r;
        while(l<=r){
            int mid=r+(l-r)/2;
            int k=0;
            for(int i:piles){
                k+=ceil((double)i/mid);
            }
            if(k>h) l=mid+1;
            else{
                ans=min(ans,mid);
                r=mid-1;
            } 
        }
        return ans;
    }      
};
