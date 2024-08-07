//Problem Link: https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int cnt = 0;
        int l = 0;
        int ans = 0;
        int total = 0;
        int n = a.size();
        for(int i = 0; i<n; i++){
            if (a[i] == 1){
                total++;
            }
            else
                cnt++;
            
            while(cnt > k){
                if (a[l] == 1)
                    total--;
                else
                    cnt--;
                l++;
            }
            ans = max(ans, i - l +1);
        }
        return ans;
        
    }
};