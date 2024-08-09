//Problem Link: https://leetcode.com/problems/remove-adjacent-almost-equal-characters/

class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            int me = 0;
            if (s[i] == s[i+1])
                    me++;
            if (s[i] == s[i-1])
                    me++;
                
            if (abs(s[i] - s[i+1]) == 1)
                    me++;
            
            if (abs(s[i] - s[i-1]) == 1)
                    me++;
            
            if (me == 2){
                    s[i] = '#';
                   ans++;
            }
        }
        for(int i = 1; i<n; i++)
            if (s[i] == s[i-1] || abs(s[i] - s[i-1]) == 1){
                    s[i] = '_';
                    ans++;
            }
        
        return ans;
    }
};