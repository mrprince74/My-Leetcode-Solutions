# Problem Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        n = len(points)
        points.sort()
        ans = 0
        i = 0
        while i < n:
            mn = points[i][1]
            j = i+1
            while j < n and points[j][0] <= mn:
                mn = min(mn, points[j][1])
                j+= 1
            ans+= 1
            i = j
        return ans