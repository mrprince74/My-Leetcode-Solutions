// Problem Link: https://leetcode.com/problems/merge-strings-alternately
class Solution {
public:
    string mergeAlternately(string a, string b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        bool left = 1;
        string ans = "";
        while(i<n && j<m){
            if(left)
                ans+= a[i++];
            else ans+= b[j++];
            left = !left;
            
        }
        while(i< n) ans+= a[i++];
        while(j<m) ans+= b[j++];
        
        return ans;
        
    }
};