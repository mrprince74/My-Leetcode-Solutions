//Problem Link: https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference/
#include <bits/stdc++.h>
using namespace std;
#define pb           push_back
#define ll           long long
#define read(a)      for(auto &i: a) cin >> i;
#define all(vec)     vec.begin(),vec.end()
#define rall(vec)     vec.rbegin(),vec.rend()
#define print(a)     for(auto i : a) cout << i << " "; cout << "\n";
#define vi           vector<int>
#define vb           vector<bool>
#define vvi          vector<vi>
#define pii          pair<int,int>
#define vii          vector<pair<int,int>>
#define prq          priority_queue
const int N = 3e5 + 3;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 3;
class Solution {
    pair<int,int> get_intersection(const pair<int,int>& a, const pair<int,int>& b){
        if (a.first == -1)
            return b;
        if (b.first == -1)
            return a;
        auto [l1, r1] = a;
        auto [l2, r2] = b;
        if (l1 > r2 || l2 > r1)
            return {-1,-1};
        return make_pair(max(l1,l2), min(r1, r2));
    }
    bool can(int dif, vector<int>& arr){
        int n = arr.size();
        bool has = false;
        pair<int,int> x = {-1,-1}, y = {-1,-1};
        for(int i = 0; i < n; i++){
            if (arr[i] != -1)
                continue;
            bool l_out = (i == 0 || arr[i-1] == -1);
            bool r_out = (i == n-1 || arr[i+1] == -1);
            if (l_out && r_out)
                continue;
            pair<int,int> l = {-1,-1}, r = {-1,-1};
            if (!l_out){
                l.first = max(1, arr[i-1] - dif);
                l.second = arr[i-1] + dif;
            }
            if (!r_out){
                r.first = max(1, arr[i+1] - dif);
                r.second = arr[i+1] + dif;
            }
            pair<int,int> me = get_intersection(l, r);
            if (me.first == -1)
                return false;
            
            if (x.first == -1){
                x = me;
                continue;
            }
            if (get_intersection(x, me).first != -1){
                x = get_intersection(x, me);
                continue;
            }
            if (y.first == -1){
                y = me;
                if (arr[i-1] == -1)
                    has = true;
            }
            else if (get_intersection(y, me).first != -1){
                y = get_intersection(y, me);
            }
            else
                return false;
        }
        if(has){
            auto in = get_intersection(x, y);
            if (in.first == -1){
                if (min(abs(x.first - y.second), abs(x.second - y.first)) > dif)
                    return false;
            }
        }
        return true;
    }
    
public:
    int minDifference(vector<int>& nums) {
        int l = 0, r = INF;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != -1 and nums[i-1] != -1)
                l = max(l, abs(nums[i] - nums[i-1]));
        }
        int ans = INF;
        while(l <= r){
            int mid = l + (r - l) / 2; 
            if (can(mid, nums)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};