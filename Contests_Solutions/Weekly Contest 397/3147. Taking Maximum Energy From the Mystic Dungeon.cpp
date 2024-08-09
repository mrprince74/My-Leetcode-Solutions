//Problem Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/


class Solution {
    const int INF = 1e9 + 3;
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n * 2 + 10, 0);
        int ans = -INF;
        for(int i = n-1; i >= 0; i--){
            dp[i] = arr[i] + dp[i + k];
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};