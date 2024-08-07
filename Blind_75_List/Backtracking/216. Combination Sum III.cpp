//Problem Link: https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    set<vector<int>> ans;
    void solve(int k, int n, vector<int> path = {}){
        if(n == 0) {
            if (path.size() == k){
                vector<int> temp = path;
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            return;
        }
        if (n < 0 or path.size() > k)
            return;
        
        int num = 1;
        if (!path.empty())
            num = path.back()+1;
        
        for(; num<=9; num++){
            if (path.empty() || path.back() != num){
                path.push_back(num);    
                solve(k,n - num, path);
                path.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};