//Problem Link: https://leetcode.com/problems/zero-array-transformation-ii/
class Solution {
    bool can(int k, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> pref(n, 0);
        for(auto q : queries){
            if (!k--)
                break;
            int l = q[0];
            int r = q[1];
            long long val = q[2];
            pref[l]+= val;
            if (r + 1 < n)
                pref[r+1]-= val;
        }
        for(int i = 0; i < n; i++){
            if (i)
                pref[i]+= pref[i-1];
            if (pref[i] < nums[i])
                return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int l = 0, r = n;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (can(mid, nums, queries)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};