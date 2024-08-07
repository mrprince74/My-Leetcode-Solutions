//Problem Link: https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> st, ans(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.back()] < arr[i]){
                ans[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
        
    }
};