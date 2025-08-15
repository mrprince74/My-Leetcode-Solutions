class Solution {
public:
    bool isPowerOfFour(int n) {
        if ((n <= 0) || (n & (n-1)))
            return false;
        cout << n << "\n";
        int pos = 31 - __builtin_clz(n);
        return pos & 1 ^ 1;
    }
};
