//Problem Link: https://leetcode.com/problems/determine-if-two-strings-are-close
class Solution {
public:
    bool closeStrings(string a, string b) {
        vector<int> f1(26), f2(26);
        for(char c: a)
                f1[c - 'a']++;
        
        for(char c: b) {
                f2[c - 'a']++;
            if (f1[c - 'a'] == 0)
                    return false;
        }
        
        vector<int> x, y;
        for(int i = 0; i<26; i++){
            x.push_back(f1[i]);
            y.push_back(f2[i]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return x == y;
        
        
        
    }
};