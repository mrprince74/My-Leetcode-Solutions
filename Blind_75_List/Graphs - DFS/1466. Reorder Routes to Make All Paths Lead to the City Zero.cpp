//Problem Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
    int ans = 0;
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& canReach, vector<bool>& visited){
        
        for(int ch: adj[node]){
            if (!visited[ch] && !canReach[ch]){
                visited[ch] = 1;
                canReach[ch] = 1;
                ans++;
                dfs(ch,adj,canReach,visited);
            }
            else if (!visited[ch])
                dfs(ch,adj,canReach,visited);
        }
        
        
    }
    bool connected(int node, vector<vector<int>> &adj, vector<bool>& canReach){
        bool ret = false;
        for(int ch: adj[node]){
            if (canReach[ch]){
                ret = true;
            }
            else {
                ret |= connected(ch,adj, canReach);
                }
        }
        // canReach[node] = ret;
        return ret;
        
    }
    public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> canReach(n,0);
        vector<int> in(n,0), out(n,0);
        canReach[0] = 1;
        for(auto edge: connections){
            int from = edge[0],to = edge[1];        
            adj[from].push_back(to);
            if (to == 0){
                canReach[from] = 1;
            }
            out[from]++;
            in[to]++;
        }
            vector<bool> visited(n,0);
        for(int i = 0; i<n; i++){
            if (canReach[i] && !visited[i]){
                dfs(i, adj, canReach, visited);
            }
        }
        
        for(int i = 0; i<n; i++){
            if (!canReach[i]){
                if (!connected(i,adj,canReach)) {
                    canReach[i] = 1;   
                    ans++;
                }
            }
                
        }
        return ans;
        
        
    }
};