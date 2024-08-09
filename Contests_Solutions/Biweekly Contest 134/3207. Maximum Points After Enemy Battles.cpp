//Problem Link: https://leetcode.com/problems/maximum-points-after-enemy-battles/

#define ll long long
class Solution {
public:
    long long maximumPoints(vector<int>& arr, int power) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int r = n-1;
        ll p = 0;
        if (power < arr[0])
            return 0LL;
        
        while(r >= 0){
            p+= ((1LL * power) / (1LL * arr[0]));
            power%= arr[0];
            power+= 0LL + arr[r--];
        }
        return p;
    }
};