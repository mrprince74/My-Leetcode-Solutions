//Problem Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> freq;
        int ans = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            freq[nums[r]]++;
            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};