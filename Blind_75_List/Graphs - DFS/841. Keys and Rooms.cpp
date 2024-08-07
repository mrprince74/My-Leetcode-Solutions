//Problem Link: https://leetcode.com/problems/keys-and-rooms/

class Solution {
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = 1;
    for(int ch: adj[node]){
        if (!vis[ch]){
            dfs(ch, adj, vis);
        }
    }
}
    
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++){
            for(int j: rooms[i]){
                adj[i].push_back(j);
            }
        }
        int count = 0;
        vector<bool> vis(n);
        for(int i = 0; i<n; i++){
            if (!vis[i]){
                count++;
                dfs(i, adj, vis);
            }
        }
        return count == 1;
        
        
    }
};