//Problem Link: https://leetcode.com/problems/edit-distance/

class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int row = word2.size(), col = word1.size();
        vector<vector<int>> dp(row+1, vector<int>(col + 1, 0));
        for(int i = 0; i<=row; i++){
            dp[i][col] =  row - i;
        }
        for(int j = 0; j<=col; j++){
            dp[row][j] =  col - j;
        }
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                if (word1[j] == word2[i]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 1 + min({
                        dp[i+1][j],
                        dp[i][j+1],
                        dp[i+1][j+1]
                    });
                }
                
            }
        }
    
        return dp[0][0];
        
    }
};