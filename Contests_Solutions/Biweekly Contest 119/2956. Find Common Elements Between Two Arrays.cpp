//Problem Link: https://leetcode.com/problems/find-common-elements-between-two-arrays/

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2);
        map<int,int> f1, f2;
        for(int num : nums1){
            f1[num]++;
        }
        for(int num : nums2){
            f2[num]++;
            if(f1[num])
                ans[1]++;
        }
        for(int num : nums1){
            if (f2[num]){
                ans[0]++;
            }
        }
        return ans;
        
    }
};