class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> nge(n,-1);
        vector<int> pge(n,-1);
        int maxi=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(height[i]<maxi) nge[i]=maxi;
            else maxi=height[i];
        }
        maxi=height[0];
        for(int i=1;i<n;i++){
            if(height[i]<maxi) pge[i]=maxi;
            else maxi=height[i];
        }
        
        int area=0;
        for(int i=0;i<n;i++){
            int mini=min(nge[i],pge[i]);
            if(mini>0) area=area+mini-height[i];
        }
        return area;
    }
};
