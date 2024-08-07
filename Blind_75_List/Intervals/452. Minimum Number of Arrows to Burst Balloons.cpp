//Problem Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int ans = 0;
        int i = 0;
        while(i < n){
            int mn = points[i][1];
            int j = i+1;
            while(j < n and points[j][0] <= mn){
                mn = min(mn, points[j][1]);
                j++;
            }      
            i = j;
            ans++;
        }
        return ans;
        
    }
};