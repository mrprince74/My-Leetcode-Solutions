// Problem Link: https://leetcode.com/problems/is-subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cur = 0;
        int i = 0;
        while(i < t.size() && cur < s.size()){
            if(t[i] == s[cur])
                cur++;
            
            i++;
        }
        
        
        return cur == s.size();
    }
};