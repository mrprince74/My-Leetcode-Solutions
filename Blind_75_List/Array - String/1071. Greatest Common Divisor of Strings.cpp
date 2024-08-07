// Problem Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/
class Solution {
public:
    bool ok(string s, string ref){
        if (s.size() % ref.size() != 0)
            return false;
        int ws = ref.size();
        int n = s.size();
        for(int i = 0; i< n -ws + 1; i+= ws){
            if (s.substr(i, ws) != ref)
                return false;
        }
        return true;
    }
    
    string gcdOfStrings(string a, string b) {
        if (a.size() > b.size())
            swap(a,b);
        string ans = "";
        string ref = a;
        while(ref.size()){
            if (ok(a, ref) && ok(b, ref)){
                ans = ref;
                break;
            }
            ref.pop_back();
        }
        return ans;
        
        
    }
};