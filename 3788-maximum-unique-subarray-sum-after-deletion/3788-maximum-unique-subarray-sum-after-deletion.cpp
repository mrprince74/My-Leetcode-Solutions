class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
        if (*max_element(s.begin(), s.end()) < 0)
            return *s.rbegin();
        for(int num : s){
            if (num > 0)
                ans+= num;
        }
        return ans;
    }
};