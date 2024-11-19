// problem link : https://leetcode.com/problems/zero-array-transformation-i/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            pref[l]++;
            if (r + 1 < n)
                pref[r+1]--;
        }
        for(int i = 0; i < n; i++){
            if (i)
                pref[i]+= pref[i-1];
            // cout << pref[i] << " ";
            if (pref[i] < nums[i])
                return false;
        }
        // cout << "\n";
        return true;
    }
};