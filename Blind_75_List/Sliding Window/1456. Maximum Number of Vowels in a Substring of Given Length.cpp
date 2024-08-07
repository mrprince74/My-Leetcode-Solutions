//Problem Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
    bool is_vowel(char c){
        string vowels = "aeiou";
        return vowels.find(c) != -1;
    }
public:
    int maxVowels(string s, int k) {
       int n = s.size();
       int ans = 0;
       int r = 0, l = 0;
       int count = 0;
       for(; r < k; r++){
           count += is_vowel(s[r]);
       }
        ans = count;
        while(r < n){
           count -= is_vowel(s[l++]);
           count += is_vowel(s[r++]);
           ans = max(ans, count);
            if (ans == k)
                break;
        }
        return ans;
        
    }
};