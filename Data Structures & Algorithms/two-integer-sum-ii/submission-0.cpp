class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> m;
        for(int i=0;i<numbers.size();i++){
            int tar=target-numbers[i];
            if(m.find(tar)!=m.end()) {
                //cout<<i<<" ";
                return {m[tar],i+1};
            }
            else m[numbers[i]]=i+1;
        }
    }
};
