// Problem Link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans = 0;
        int i = 0, j = a.size() - 1;
        while(i < j){
            ans = max(ans, min(a[i], a[j]) * (j - i));
            if (a[i] < a[j])
                    i++;
            else
                j--;
        }
        return ans;
    }
};