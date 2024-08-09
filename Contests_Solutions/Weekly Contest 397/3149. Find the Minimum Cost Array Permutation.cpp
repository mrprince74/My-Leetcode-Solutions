//Problem Link: https://leetcode.com/problems/find-the-minimum-cost-array-permutation/

// Note: I couldn't solve this problem in the contest time. However, I managed to upsolve it after the contest was done

const int N = 1e5 + 3;
const int INF = 1e9 + 3;
const int MOD = 1e9 + 7;
int dp[14][14][1 << 14];
class Solution {
    vector<int> arr;
    int n;
    int solve(int prev, int st, int msk){
        int& me = dp[prev][st][msk];
        if (~me)
            return me;
        
        int rem = __builtin_popcount((1 << n) - 1 - msk);
        if (rem == 0){ // if last item in the permutation
            return me =  abs(prev - arr[st]);
        }
        me = INF;
        for(int bit = 0; bit < n; bit++){
            if (msk & (1 << bit))
                continue;
            int new_msk = (msk | (1 << bit));
            me = min(me, 
            solve(bit,st,new_msk) + abs(prev - arr[bit]));
        }
        return me;
    }


    void build(int prev, int st, int msk, vector<int>& ans){
        int rem = __builtin_popcount((1 << n) - 1 - msk);
        if (rem == 0){
            return;
        }
        int me = solve(prev, st, msk);
        
        for(int bit = 0; bit < n; bit++){
            if (msk & (1 << bit))
                continue;
            int new_msk = msk | (1 << bit);
            if (me == solve(bit,st,new_msk) + abs(prev - arr[bit])){
                ans.push_back(bit);
                build(bit, st, new_msk, ans);
                break;
            }
        }
    }




public:
    vector<int> findPermutation(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        memset(dp, -1, sizeof dp);
        int best_val = INF;
        int best_st = -1;
        for(int i = 0; i < n; i++){
            int msk = (1 << i);
            if (solve(i, i, msk) < best_val){
                best_val = solve(i, i, msk);
                best_st = i;
            }
        }
        vector<int> ans{best_st};
        build(best_st, best_st, (1 << best_st), ans);
        return ans;
    }
};