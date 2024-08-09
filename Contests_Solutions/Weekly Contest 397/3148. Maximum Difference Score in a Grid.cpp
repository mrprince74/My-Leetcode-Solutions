//Problem Link: https://leetcode.com/problems/maximum-difference-score-in-a-grid/

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        int ans = -1e9;
        for(int i = n-2; i >= 0; i--){
            pref[i][m-1] = max(pref[i+1][m-1], grid[i+1][m-1]);
            ans = max(ans, -grid[i][m-1] + pref[i][m-1]);
        }
        
        
        for(int j = m-2; j >= 0; j--){
            pref[n-1][j] = max({
                pref[n-1][j+1],
                grid[n-1][j+1],
                });
            ans = max(ans, -grid[n-1][j] + pref[n-1][j]);
        }
        
        
        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                pref[i][j] = max({
                    pref[i+1][j],
                    pref[i][j+1],
                    grid[i+1][j],
                    grid[i][j+1]
                    
                    });
                ans = max(ans, -grid[i][j] + pref[i][j]);
            }
        }

        return ans;


    }
};

