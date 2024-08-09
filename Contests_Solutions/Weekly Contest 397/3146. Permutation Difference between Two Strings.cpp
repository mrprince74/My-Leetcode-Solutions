//Problem Link: https://leetcode.com/problems/permutation-difference-between-two-strings/

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> where;
        for(int i = 0; i < s.size(); i++){
            where[s[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans+= abs(i - where[t[i]]);
        }
        return ans;
    }
};