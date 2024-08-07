# Problem Link: https://leetcode.com/problems/longest-common-subsequence/

class Solution:
    def longestCommonSubsequence(self, a: str, b: str) -> int:
        row = len(a)
        col = len(b)
        dp = [[0 for j in range(col+1)] for i in range(row+1)]
        for i in range(row-1,-1,-1):
            for j in range(col-1,-1,-1):
                if a[i] == b[j]:
                    dp[i][j] = 1 + dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])
        
        
        
        
        return dp[0][0]