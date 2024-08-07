//Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost.back(), b = 0;
        int n = cost.size();
        int me = a;
        for(int i = n-2; i>=0; i--){
            if (i != 0){
            me = min(a,b) + cost[i];
            }
            else
                me = min(me, min(a,b) + cost[i]);
            b = a;
            a = me;
        }
        return me;
        
    }
};