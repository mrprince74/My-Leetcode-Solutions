//Problem Link:  https://leetcode.com/problems/number-of-provinces

void dfs(int node, vector<vector<int>>& adj , vector<int>& vis){
vis[node] = 1;
    for(int ch: adj[node]){
        if (!vis[ch])
            dfs(ch, adj, vis);
    }
}

class Solution {        
public:
    int findCircleNum(vector<vector<int>>& isConnected) { 
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if (isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
        int ans = 0;
        vector<int> vis(n,0);
        for(int i = 0; i<n; i++){
            if (!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }
        
        return ans;
        
    }
};
