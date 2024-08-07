// Problem Link: https://leetcode.com/problems/reverse-vowels-of-a-string
class Solution {
public:
        
    string reverseVowels(string s) {
        unordered_map<char, bool> vowel;
        for (char c :"aeiouAEIOU")
            vowel[c] = 1;
        int n = s.size();
        int i = 0, j = n-1;
        while(i < j){
            if (!vowel[s[i]])
                i++;
            
            else if (!vowel[s[j]])
                j--;
            else{
                swap(s[i], s[j]);
                i++,j--;
            }   
        }
        return s;
    }
};