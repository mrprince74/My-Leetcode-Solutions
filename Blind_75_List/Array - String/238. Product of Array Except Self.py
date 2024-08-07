# Problem Link: https://leetcode.com/problems/product-of-array-except-self/
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # Initialization
        pref = [0] * n
        suf = [0] * n
        pref[0] = nums[0]
        suf[-1] = nums[-1]
        ans = [0] * n
        
        for i in range(1, n):
            pref[i] = pref[i-1] * nums[i]
        
        for i in range(n-2, -1, -1):
            suf[i] = suf[i+1] * nums[i]
            
        for i in range(n):
            left = 1
            right = 1
            if i != 0:
                left = pref[i-1]
            
            if i != n-1:
                right = suf[i+1]
            
            ans[i] = left * right
        
        
        return ans