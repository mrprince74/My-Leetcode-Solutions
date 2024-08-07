//Problem Link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
        
    int ok(vector<int> &nums, int cap, int h){
        int ret = 0;
        for(int num: nums){
            ret += (num + cap - 1) / cap;
        }
        return ret <= h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = INT_MAX;
        int ans = INT_MAX;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (ok(piles, mid, h)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid +1;
        }
        
        return ans;
    }
};