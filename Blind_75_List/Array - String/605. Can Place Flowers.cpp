// Problem Link: https://leetcode.com/problems/can-place-flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int req) {
        int n = a.size();
        for(int i = 0;i<n; i++){
            if (a[i] == 0){
                bool left = (i == 0 || a[i-1] == 0);
                bool right = (i == n-1 || a[i+1] == 0);
            if (left && right){
                req--;
                a[i] = 1;
            }
            }
            
        }
        return req <= 0;
        
    }
};