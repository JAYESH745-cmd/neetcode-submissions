class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int count=0;
        int i=0,j=0;
        int n=s.length();
        while(j<n){
            if(st.find(s[j])==st.end()) {
                count=max(count,j-i+1);
                st.insert(s[j]);
                j++;  
            }
            else {
                st.erase(s[i]);
                i++; 
            }
            
        }
        return count;
    }
};
