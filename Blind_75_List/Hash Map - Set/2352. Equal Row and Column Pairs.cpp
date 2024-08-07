//Problem Link: https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows, cols;
        int n = grid.size();
        for(int i = 0; i<n; i++){
            vector<int> row = grid[i];
            rows[row]++;
            vector<int> col;
            for(int j = 0; j < n; j++){
                col.push_back(grid[j][i]);
            }
            cols[col]++;
        }
        int ans = 0;
        for(auto [key, val]: cols){
            ans += val * rows[key];
        }
        return ans;
    }
};