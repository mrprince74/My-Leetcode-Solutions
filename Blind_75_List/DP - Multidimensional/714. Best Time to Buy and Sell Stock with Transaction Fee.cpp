//Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int dp[50004][2]; // dp[i] : {buy, sell}
    int cost;
    int n;
    vector<int> a;
    const int INF = 1e9 + 3;
    int solve(int i, int prev){
        if (i == n){
            return 0;
        }
        int& me = dp[i][prev];
        if (me != -1)
            return me;
        
        me = solve(i+1, prev); // Don't take
        
        if (prev == 0) // if previous was buy ==> Sell
            me = max(me, a[i] + solve(i+1, 1)); // sell
        else
            me = max(me, -a[i] - cost + solve(i+1, 0)); // buy
                
        return me;
        
        
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        a = prices;
        n = a.size();
        cost = fee;
        memset(dp, -1, sizeof dp);
        solve(0,1);
        int ans = 0;
        return dp[0][1];
    }
};