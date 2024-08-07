//Problem Link: https://leetcode.com/problems/rotting-oranges

class Solution {
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
    const int inf = 1e9 + 3;

    bool ok(int i, int j, int n, int m){
        return 0 <= i && i <n && 0 <= j && j < m;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, inf));
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            const auto& [x, y] =  q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int x_ = x + dx[dir], y_ = y + dy[dir];
                if (ok(x_, y_, n, m) && grid[x_][y_] == 1){
                    int& my_dis = dis[x_][y_];
                    int his_dis = dis[x][y];
                    if (my_dis == inf) {// not visited
                        my_dis = his_dis + 1;
                        q.push({x_, y_});
                    }
                    else{
                    my_dis = min(my_dis, his_dis + 1);
                    }
                }
                
            }
        }
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                if (grid[i][j] != 0)   
                ans = max(ans, dis[i][j]);
            }
        
        return (ans == inf? -1: ans);
        
    }
};