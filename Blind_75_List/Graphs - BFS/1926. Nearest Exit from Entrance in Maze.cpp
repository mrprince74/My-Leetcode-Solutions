//Problem Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
    const int inf = 1e9 + 3;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
public:
    int nearestExit(vector<vector<char>>& mat, vector<int>& entrance) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int>(m, inf));
        q.push({entrance[0], entrance[1]});
        dis[entrance[0]][entrance[1]] = 0;
        mat[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            // cout << q.size() << "\n";
            auto top = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int x = top.first + dx[dir], y = top.second + dy[dir];
                if (0 <= x && x < n && 0 <= y && y < m && mat[x][y] == '.'){
                    q.push({x,y});
                    dis[x][y] = dis[top.first][top.second] + 1;
                    mat[x][y] = '+';
                }
            }
        }
        
        int ans = inf;
        dis[entrance[0]][entrance[1]] = inf;
        for(int i = 0; i<n; i++){
            ans = min({ans, dis[i][0],dis[i][m-1]});
        }
        for(int j = 0; j<m; j++){
            ans = min({ans, dis[0][j], dis[n-1][j]});
        }
        return (ans == inf? -1: ans);
        
    }
};