// Problem Link: https://leetcode.com/problems/move-zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nxt = 0;
        for(int i = 0; i < n; i++){
            if (nums[i] != 0){
                nums[nxt++] = nums[i];
            }
        }
        while(nxt < n){
            nums[nxt++] = 0;
        }
    
    }
};