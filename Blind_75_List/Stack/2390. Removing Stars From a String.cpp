//Problem Link: https://leetcode.com/problems/removing-stars-from-a-string/

class Solution {
public:
    string removeStars(string s) {
        string ret = "";
        for(char c: s){

            if (c != '*') ret+= c;
            else ret.pop_back();
        }
        return ret;
    }
};