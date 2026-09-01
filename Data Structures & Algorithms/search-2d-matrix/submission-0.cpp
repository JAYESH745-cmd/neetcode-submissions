class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int n=matrix.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            int n1=matrix[i].size();
            if(matrix[i][n1-1]>tar) {
                idx=i;
                break;
            }
        }
        cout<<idx;
        if(idx==-1) return false;
        int l=0,r=matrix[idx].size()-1;
        while(l<=r){
            int mid=r+(l-r)/2;
            if(matrix[idx][mid]==tar) return true;
            else if(matrix[idx][mid]>tar) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
