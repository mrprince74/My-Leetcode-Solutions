# Problem Link: https://leetcode.com/problems/dota2-senate/
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        l = collections.deque()
        r = collections.deque()
        for i,c in enumerate(senate):
            if c == 'R':
                r.append(i);
            else:
                l.append(i)
        while l and r:
            if l[0] < r[0]:
                r.popleft()
                l.append(l.popleft() + n)
            else:
                l.popleft()
                r.append(r.popleft() + n)
        
        if l:
            return "Dire"
        else:
            return "Radiant"
        
        