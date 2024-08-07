//Problem Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& ref, long long success) {
        sort(ref.begin(), ref.end());
        vector<int> ans;
        int m = ref.size();
        for(int num: spells){
            long long val = (success + num - 1) / num;
            if (val > ref.back()){
                ans.push_back(0);
                continue;
            }
            auto it = lower_bound(ref.begin(), ref.end(), val); // pos of first x >= val;
            int pos = m - (it - ref.begin());
            ans.push_back(pos);
        }
        return ans;
        
    }
};