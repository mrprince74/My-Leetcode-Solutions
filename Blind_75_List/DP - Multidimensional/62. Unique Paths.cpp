//Problem Link: https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int dp[101][101];
    int N, M;
    int solve(int i, int j){
        int& me = dp[i][j];
        if (~me)
            return me;
        
        int op1 = i+1 < N? solve(i+1,j): 0;
        int op2 = j+1 < M? solve(i, j+1): 0;
        return me = op1 + op2;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        N = n, M = m;
        dp[N-1][M-1] = 1;
        return solve(0,0);
    }
};