//Problem Link: https://leetcode.com/problems/find-the-difference-of-two-arrays
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        map<int, bool> in_a, in_b;
        for(int x : a)
           in_a[x] = 1;
        for(int x: b)
           in_b[x] = 1;
        vector<vector<int>>ans(2);
        for(int x: a)
            if(!in_b[x]){
            ans[0].push_back(x);
                in_b[x] = 1;
            }
        
        for(int x: b)
            if(!in_a[x]){
                in_a[x] = 1;
            ans[1].push_back(x);
            }
        
        return ans;
     }
};