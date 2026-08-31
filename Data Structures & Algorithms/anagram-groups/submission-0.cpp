class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return {{}};
        
        map<map<char,int>,vector<int>>m;
        
        for(int i=0;i<n;i++){
            map<char,int> temp;
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]]++;
            }
            auto t=m.find(temp);
            if(t!=m.end()) t->second.push_back(i);
            else m[temp]={i};
        }
        int n1=m.size();
        vector<vector<string>> ans(n1);
        int k=0;
        for(auto i:m){
            for(int j=0;j<i.second.size();j++){
                cout<<strs[i.second[j]]<<" ";
                
            }
            cout<<endl;
        }
        // int j=n1-1;
        // for(auto i:m){
        //     for(int j=0;j<i.second.size();j++){
        //         ans[j--].push_back(strs[i.second[j]]);
        //     }
        // }
        return ans;
    }
};
