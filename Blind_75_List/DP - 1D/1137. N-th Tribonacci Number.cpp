//Problem Link: https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n<=2) return 1;
        int a = 0, b = 1 , c = 1;
        int total;
        for(int i =1; i<n-1;i++){
            total = a + b + c;
            a = b;
            b = c;
            c = total;
        }
        return total;
    }
};