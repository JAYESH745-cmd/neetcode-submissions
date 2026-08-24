class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i:nums){
            s.insert(i);
        }
        int ans=0;
        for(int i :s){
            if(s.find(i-1)==s.end()){
                int curr=i;
                int count=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    count++;
                }
                ans=max(count,ans);
            }
        }
        return ans;
    }
};
