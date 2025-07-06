const int INF = 1e9 + 10;
class Solution {
    vector<vector<pair<int,int>>> adj; // {time, node}
    vector<int> vis;
    int id = 0;
    void dfs(int curTime, int node){
        vis[node] = id;
        for(auto [time, ch] : adj[node]){
            if (vis[ch] == id)
                continue;
            if (time > curTime)
                dfs(curTime, ch);
        }
    }
public:
    Solution(){
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        adj.resize(n);
        for(auto e : edges){
            int a = e[0], b = e[1], time = e[2];
            adj[a].emplace_back(time, b);
            adj[b].emplace_back(time, a);
        }
        vis.resize(n, 0);
        int l = 0, r = INF;
        int ans = -1;
        auto ok = [&](int curTime){
            int cmpCount = 0;
            id++;
            for(int i = 0; i < n and cmpCount < k; i++){
                if (vis[i] == id)
                    continue;
                dfs(curTime, i);
                cmpCount++;
            }
            return cmpCount >= k;
        };

        while(l <= r){
            int mid = l + (r - l) / 2;
            if (ok(mid)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};