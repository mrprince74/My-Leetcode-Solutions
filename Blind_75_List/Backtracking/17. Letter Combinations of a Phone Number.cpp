//Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    unordered_map<char, string> chars;
    vector<string> ans;
    void gen(const string &digits, int idx, string& so_far){
        if (idx == digits.size()){
            if (!so_far.empty())
                ans.push_back(so_far);
            
            return;
        }
        
        for(char c: chars[digits[idx]]){
        so_far.push_back(c);
        gen(digits, idx+1, so_far);   
        so_far.pop_back();
        }
        
        
    }
        
    
public:
    vector<string> letterCombinations(string digits) {
        chars['2'] = "abc";
        chars['3'] = "def";
        chars['4'] = "ghi";
        chars['5'] = "jkl";
        chars['6'] = "mno";
        chars['7'] = "pqrs";
        chars['8'] = "tuv";
        chars['9'] = "wxyz";
        string so_far;
        gen(digits, 0, so_far);
        return ans;
        
        
        
        
    }
};