//Problem Link: https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    map<string, bool> vis;
    const double inf = -1;
    double dfs(string node, string goal, unordered_map<string, vector<pair<string, double>>> adj, double so_far = 1){
        vis[node] = 1;
        if (node == goal && adj.count(node)){
            return so_far;
        }
        for(auto [ch, cost]: adj[node]){
            if (!vis[ch]){
             double val = (dfs(ch, goal, adj, so_far * cost));
            if (val != -1)
                 return val;
             }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i<values.size(); i++){
            auto e = equations[i];
            double val = values[i];
            string from = e[0], to = e[1];
            adj[from].push_back({to, val});
            adj[to].push_back({from, 1 / val});
        }
        vector<double> ans;
        for(auto q: queries){
            vis.clear();
            string from = q[0], to = q[1];
            double val = dfs(from, to, adj);
            ans.push_back(val);
        }
        return ans;
        
        
        
    }
};