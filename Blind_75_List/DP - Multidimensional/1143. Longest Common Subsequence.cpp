//Problem Link: https://leetcode.com/problems/longest-common-subsequence/

class Solution {
    string s, t;
    int dp[1001][1001];
    int solve(int i, int j){
        if (i == s.size() || j == t.size())
                return 0;
        int& me = dp[i][j];
        if (~me)
            return me;
        if (s[i] == t[j]){
            return me = 1 + solve(i+1, j+1);
        }
        return me = max(
        solve(i+1, j),
        solve(i, j+1)
        );
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        s = text1;
        t = text2;
        memset(dp, -1, sizeof dp);
        return solve(0,0);
    }
};