// Problem Link: https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, nums[0]), suf(n, nums[n-1]);
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] * nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1] * nums[i];
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int l = 1, r = 1;
            if (i){
                l = pref[i-1];
            }
            if (i != n-1){
                r = suf[i+1];
            }
            ans[i] = l * r;
        }
        return ans;
    }
};