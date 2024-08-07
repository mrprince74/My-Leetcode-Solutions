# Problem Link: https://leetcode.com/problems/non-overlapping-intervals/

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        ans = 0
        prev_max = -float("inf")
        intervals.sort()
        for [a,b] in intervals:
            if a >= prev_max:
                prev_max = b
            else:
                ans+=1
                prev_max = min(prev_max, b)
        return ans