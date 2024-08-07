//Problem Link: https://leetcode.com/problems/single-number/

// Sol 1: (Intended solution using xor)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int num : nums)
            x^= num;
        return x;
    }
};

// Sol 2: (Not the intended solution)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums)
            freq[i]++;
        int ans;
        for(auto [a,b]: freq)
            if (b == 1) ans = a;
        
        return ans;
    }
};