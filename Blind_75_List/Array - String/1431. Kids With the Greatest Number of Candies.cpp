// Problem Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans(n);
        int mx = *max_element(candies.begin(),candies.end());
        
        for(int i = 0; i<n; i++){
        ans[i] = (candies[i] + extraCandies >= mx);
        }
        return ans;
    }
};