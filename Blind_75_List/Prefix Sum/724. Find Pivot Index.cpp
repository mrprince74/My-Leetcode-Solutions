//Problem Link: https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    #define print(a) for(auto i : a) cout << i << " "; cout << "\n";
    int pivotIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        vector<int> pre(n,0),suf(n,0);
        pre[0] = nums[0];
        suf[n-1] = nums.back();
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i = n-2; i>=0; i--){
            suf[i] = suf[i+1] + nums[i];
        }
        // print(pre);
        // print(suf);
        for(int i = 0; i<n; i++){
            int l = pre[i] - nums[i];
            int r = suf[i] - nums[i];
            // printf("Index: %d Before: %d After: %d\n", i,l,r);
            if (l == r){
                ans = i;
                break;
            }
        }    
        return ans;
    }
};