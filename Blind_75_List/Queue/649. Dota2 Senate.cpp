//Problem Link: https://leetcode.com/problems/dota2-senate/
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,l;
        int n = senate.size();
        for(int i = 0; i<senate.size(); i++){
            if (senate[i] == 'R')
                r.push(i);
            else
                l.push(i);
        }
        while(!r.empty() && !l.empty()){
            if (r.front() < l.front()){
                l.pop();
                r.push(r.front() + n);
                r.pop();
            }
            else{
                r.pop();
                l.push(l.front() + n);
                l.pop();
                
            }

        }
        
        if (l.empty()){
            return "Radiant";
        }
        else
            return "Dire";
        
    }
};