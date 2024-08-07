//Problem Link: https://leetcode.com/problems/domino-and-tromino-tiling/

const int MOD = 1e9 + 7;
class Solution {
    int dp[1010];
public:
    int numTilings(int n) {
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= n; i++){
            dp[i] = (2 * dp[i-1] % MOD + dp[i-3]) % MOD;
        }
        return dp[n];
    }
};