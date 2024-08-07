//Problem Link: https://leetcode.com/problems/total-cost-to-hire-k-workers/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long,int>>> head, tail;
        long long ans = 0;
        int n = costs.size();
        cout << n << "\n";
        int next = candidates, prev = n - candidates - 1;
        
        for(int i = 0; i < next; i++){
            head.push({costs[i],i});
        }
        for(int i = max(next, n - candidates); i<n; i++){
                tail.push({costs[i], i});
        }
        while(k--){
            if (head.empty() || (!tail.empty() && tail.top() < head.top())){
                ans+= tail.top().first;
                tail.pop();
                if (next <= prev)
                        tail.push({costs[prev], prev--});
            }
            else{
                ans+= head.top().first;
                head.pop();
                if (next <= prev)
                        head.push({costs[next], next++});
            }
        }        
    
        return ans;
    }
};