# Problem Link: https://leetcode.com/problems/edit-distance/

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = {("","") : 0}
        def lev(a: str,b:str)->int:
            if dp.get((a,b), -1) != -1:
                return dp[(a,b)]
            
            if len(a) == 0:
                dp[(a,b)] = len(b)
                return len(b)
            
            if len(b) == 0:
                dp[(a,b)] = len(a)
                return len(a)
            
            if a[0] == b[0]:
                dp[(a,b)] = lev(a[1:], b[1:])
                return dp[(a,b)]
            
            x = dp[(a,b[1:])] = lev(a,b[1:])
            
            y = dp[(a[1:],b[1:])] = lev(a[1:],b[1:])
            
            z = dp[(a[1:],b)] = lev(a[1:],b)
            
            dp[(a,b)] = min(x,y,z) + 1
            return dp[(a,b)]
        return lev(word1,word2)