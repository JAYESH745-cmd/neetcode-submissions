class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m1;
        for(char i:s1){
            m1[i]++;
        }
        map<char,int>m2;
        for(int i=0;i<s1.length();i++){
            m2[s2[i]]++;
        }
        if(m2==m1) return true;
        int i=0,j=s1.length();
        int n=s2.length();
        while(j<n){
            m2[s2[i]]--;
            if(m2[s2[i]]==0) m2.erase(s2[i]);
            m2[s2[j]]++;
            if(m2==m1) return true;
            i++;j++;
        }
        return false;
    }
};
