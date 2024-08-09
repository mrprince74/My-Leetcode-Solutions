//Problem Link: https://leetcode.com/problems/alternating-groups-i/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k = 3) {
        int n = arr.size();
        vector<int> pref(n,0);
        for(int i = 0; i < n; i++){
            int left = ((i - 1) % n + n) % n;
            int right = (i + 1) % n;
            if (arr[left] != arr[i] and arr[i] != arr[right])
                pref[i]++;
            if (i)
                pref[i]+= pref[i-1];
        }
        int ans = 0;
        int l = 0, r = k-1;
        while(l < n){
            int cnt = 0;
            if (l < r){
                cnt = pref[r] - (l? pref[l-1] : 0);
                // if (pref[l])
                //     cnt--;
                // if (pref[r])
                //     cnt--;
            }
            else{
                cnt = pref.back() - pref[l-1];
                cnt+= pref[r];
                // if (pref[l])
                //     cnt--;
                // if (pref[r])
                //     cnt--;
            }
            int left_l = ((l-1) % n + n) % n;
            int right_l = (l + 1) % n;
            
            if (arr[left_l] != arr[l] and arr[l] != arr[right_l])
                cnt--;
            
            int left_r = ((r-1) % n + n) % n;
            int right_r = (r + 1) % n;
            
            if (arr[left_r] != arr[r] and arr[r] != arr[right_r])
                cnt--;
            
                
            if (cnt == k-2){
                // cout << "Starting from " << l << "\n";
                ans++;
            }
            l++, r++;
            r%= n;
        }
        return ans;
        
        
    }
};