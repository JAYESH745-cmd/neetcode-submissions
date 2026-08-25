class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int area=0;
        while(i<j){
            int water=(j-i)*min(heights[j],heights[i]);
            area=max(area,water);
            if(heights[i]>heights[j]) j--;
            else i++;
        }
        return area;
    }

};
