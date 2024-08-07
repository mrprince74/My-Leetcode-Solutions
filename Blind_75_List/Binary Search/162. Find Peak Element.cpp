//Problem Link: https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            bool right = mid == n-1 || nums[mid+1] < nums[mid];
            bool left = mid == 0 || nums[mid-1] < nums[mid];
            if (left && right){
                return mid;
            }
            if (left){
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        
     return -1;   
        
    }
};