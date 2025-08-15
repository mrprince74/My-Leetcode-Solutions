class Solution {
public:
    bool isPowerOfFour(int n) {
        if (__builtin_popcount(n) != 1)
            return false;
        int pos = 31 - __builtin_clz(n);
        return pos & 1 ^ 1;
    }
};
