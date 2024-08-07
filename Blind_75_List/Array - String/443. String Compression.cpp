// Problem Link: https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.back() != '#')
            chars.push_back('#');
        else
            chars.push_back('/');
        
        int n = chars.size();
        int c = 1;
        char cur = chars[0];
        string ref = "";
        for(int i = 1; i<n; i++){
            if (chars[i] == cur){
                c++;
            }
            else{
                ref+= cur;
                if (c > 1){
                    ref+= to_string(c);
                }
                cur = chars[i];
                c = 1;
            }
        }
        chars.pop_back();
        for(int i = 0; i<ref.size(); i++){   
            if (i >= chars.size())
                chars.push_back(ref[i]);
            else
                chars[i] = ref[i];
        }
        while(chars.size() > ref.size())
            chars.pop_back();
        
        
        return chars.size();
        
    }
};