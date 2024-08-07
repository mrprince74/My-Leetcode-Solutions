//Problem Link: https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    const int inf = 1e9 + 3;
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();
        for(int i = 1; i<n ;i++){
            a[i] = a[i-1] + a[i];
        }
        double ans = -inf;
        for(int i = 0; i + k - 1 < n; i++){
            int l = 0, r = a[i + k - 1];
            if (i > 0) l = a[i-1];
            
            ans = max(ans, (double) (r - l) / k);
        }
        return ans;
        
    }
};