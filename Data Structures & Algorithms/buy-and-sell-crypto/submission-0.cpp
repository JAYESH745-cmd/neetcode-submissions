class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sm=prices[0];
        int prof=0;
        for(int i=1;i<n;i++){
            if(sm<prices[i]) prof=max(prof,prices[i]-sm);
            else sm=prices[i];
        }
        return prof;
    }
};
