class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=1;
        int n=s.length();
        int count=0;
        // set<char> st;
        while(j<n){
            if(s[j]==s[i]){
                count=max(count,j-i+1);
                j++;
            }
            else if(k>0){
                count=max(count,j-i+1);
                j++;
                k--;
            }
            else{
                i++;
                //k++;
            }
        }
        return count;
    }
};
