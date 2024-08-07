//Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/


// Sol 1: Sliding Window
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 0;
        int c = 0;
        int ans = 0;
        while(j < n){
            c += a[j++] == 0;
            while(c > 1){
                c -= (a[i++] == 0);
            }
            ans = max(ans, j - i-1);
        }
        return ans;
        
    }
};

// Sol 2: Stack
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> next(n,n), prev(n,-1);
        vector<int> st;
        for(int i = 0; i<n; i++){
            if (st.empty() || a[i] == 1){
                st.push_back(i);
            }
            else{
                while(!st.empty()){
                    next[st.back()] = i;
                    st.pop_back();
                }
                st.push_back(i);
            }
        }
        st.clear();
        for(int i = n-1; i>=0; i--){
            if (st.empty() || a[i] == 1){
                st.push_back(i);
            }
            else{
                while(!st.empty()){
                    prev[st.back()] = i;
                    st.pop_back();
                }
                st.push_back(i);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            int l = prev[i] + 1;
            int r = next[i] - 1;
            ans = max(ans, r - l);
        }
        return ans;
        
    }
};