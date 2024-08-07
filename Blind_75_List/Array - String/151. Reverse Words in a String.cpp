// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ret = "";        
        string word = "";
        
        for(int i = n-1; i>=0; i--){
            char c = s[i];
            if (c == ' '){
             if (word.size()){
                 reverse(word.begin(), word.end());
                 ret += word + " ";
             }
                 word = "";
            }
            else word += c;
        }
        if (word.size()){
         reverse(word.begin(), word.end());
            ret += word + " ";
        }
        
        ret.pop_back();
            
        return ret;
    }
};