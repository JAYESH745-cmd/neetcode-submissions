class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0;
        int n=s.length();
        int ans=0;
        int maxFreq=0;
        map<char,int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            maxFreq=max(maxFreq,m[s[i]]);
            while((i-j+1)-maxFreq>k){
                m[s[j]]--;
                if(m[s[j]]==0) m.erase(s[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        
        return ans;;
    }
};
