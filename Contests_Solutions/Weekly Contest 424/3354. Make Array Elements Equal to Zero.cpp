//Problem Link: https://leetcode.com/problems/make-array-elements-equal-to-zero/

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> pref(n, 0);
        for(int i = 0; i < n; i++){
            pref[i] = nums[i];
            if (i)
                pref[i]+= pref[i-1];
        }
        for(int i = 0; i < n; i++){
            if (nums[i] == 0){
                int l = pref[i];
                int r = pref.back() - pref[i];
                if (l == r)
                    ans+= 2;
                else if (abs(l - r) == 1)
                    ans++;
            }
        }
        return ans;
    }
};