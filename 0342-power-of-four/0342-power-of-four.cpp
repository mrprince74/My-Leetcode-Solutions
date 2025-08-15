class Solution {
public:
    bool isPowerOfFour(int n) {
        if ((n <= 0) || (n & (n-1) != 0))
            return false;
        int pos = 31 - __builtin_clz(n);
        return pos & 1 ^ 1;
    }
};
