// Problem Link: https://leetcode.com/problems/increasing-triplet-subsequence/

// Solution 1:
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suf(n);
        pref[0] = nums[0];
        suf.back() = nums.back();
        for(int i = 1; i < n; i++){
            pref[i] = min(pref[i-1], nums[i]);
        }
        for(int i = n-2; i>= 0; i--){
            suf[i] = max(suf[i+1] , nums[i]);
        }
        
        for(int i = 1; i < n-1; i++){
            if (pref[i-1] < nums[i] && nums[i] < suf[i+1])
                    return true;
        }
        
        return false;
        
        
        
    }
};

// Solution 2 (Using Sparse Table. Not recommended in interviews. Wrote it just for fun :) ): 
class Sparse{
    vector<vector<int>> SP;
    bool is_min;
    void build(const vector<int>& arr){
        int n = arr.size();
        int lg = 32 - __builtin_clz(n);
        SP.resize(lg, vector<int>(n));
        SP[0] = arr;
        for(int bit = 1; (1 << bit) <= n; bit++){
            for(int i = 0; i + (1 << bit) <= n; i++){
                if (is_min){
                    SP[bit][i] = min(
                        SP[bit-1][i],
                        SP[bit-1][i + (1 << (bit - 1))]
                    );
                }
                else{
                    SP[bit][i] = max(
                        SP[bit-1][i],
                        SP[bit-1][i + (1 << (bit - 1))]
                    );
                }
            }
        }
    }
public:
    Sparse(const vector<int>& arr, string fun){
        is_min = (fun == "min");
        build(arr);
        
    }
    int query(int l, int r){
        int lg = 31 - __builtin_clz(r - l + 1);
        if (is_min){
            return min(
                SP[lg][l],
                SP[lg][r - (1 << lg) + 1]
            );
        }
        return max(
                SP[lg][l],
                SP[lg][r - (1 << lg) + 1]
            );
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        Sparse mn(nums, "min"), mx(nums,"max");
        
        
        for(int i = 1; i < n-1; i++){
            int l = mn.query(0, i-1);
            int r = mx.query(i+1, n-1);
            // printf("%d %d %d\n", l, nums[i], r);
            if (l < nums[i] && nums[i] < r)
                return true;
        }
        
        return false;
        
        
        
    }
};