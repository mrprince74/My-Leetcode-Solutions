//Problem Link: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    const int inf = 1e9 + 3;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev_max = -inf;
        int ans = 0;
        for(auto& p: intervals){
            if (p[0] >= prev_max){
                prev_max = p[1];
            }
            else{
                ans++;
                prev_max = min(prev_max, p[1]);
            }
        }
        
        return ans;
    }
};