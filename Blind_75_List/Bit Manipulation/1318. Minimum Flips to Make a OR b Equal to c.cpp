//Problem Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i<32; i++){
            int a1 = (1 & a);
            int b1 = (1 & b);
            int c1 = (1 & c);
            
            if ((a1 | b1) != c1){
                ans++;
                if (c1 == 0 && a1 == 1 && b1 == 1){
                    ans++;
                }
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
        }
        
        return ans;
    }
};