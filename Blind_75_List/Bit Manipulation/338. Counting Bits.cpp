//Problem Link: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> a;
        for(int i = 0; i<=n ;i++){
            int val = 0;
            for(int bit = 0; bit<31; bit++){
                val += ((i >> bit) & 1);
            }
            a.push_back(val);
        }
        return a;
    }
};