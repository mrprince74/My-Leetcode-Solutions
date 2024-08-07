//Problem Link: https://leetcode.com/problems/house-robber/


// Iterative
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int v2 = 0;
        int v1 = nums.back();
        int ans = v1;
        for(int i = n-2; i >= 0; i--){
            int op1 = v1;
            int op2 = nums[i] + v2;
            ans = max(op1, op2);
            v2 = v1;
            v1 = ans;
        }
        return ans;
    }
};

// Recursive

class Solution {
    int n;
    vector<int> arr;
    int dp[101];
    int solve(int i){
        if (i >= n)
            return 0;
        int& me = dp[i];
        if (~me)
            return me;
        int op1 = solve(i+1);
        int op2 = arr[i] + solve(i+2);
        return me = max(op1, op2);
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        memset(dp, -1, sizeof dp);
        return solve(0);
    }
};