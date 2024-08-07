//Problem Link: https://leetcode.com/problems/find-the-highest-altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int prev = 0;
        for(const int &x: gain){
            prev += x;
            ans = max(ans, prev);
        }
        
        return ans;
    }
};