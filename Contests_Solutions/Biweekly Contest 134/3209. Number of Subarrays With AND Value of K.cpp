//Problem Link: https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/

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
const int INF = 1e9 + 3;
const int MOD = 1e9 + 7;
template<typename T, class CMP = function<T(const T &, const T &)>>
class SparseTable{
private:
    CMP merge;
    vector<vector<T>> SP;
    void build(const vector<T>& arr){
        int n = arr.size();
        int lg = 32 - __builtin_clz(n);
        SP = vector<vector<int>>(lg, vector<int>(n));
        SP[0] = arr;
        for(int msk = 1; (1 << msk) <= n; msk++){
            for(int i = 0; i + (1 << msk) <= n; ++i){
                SP[msk][i] = merge(SP[msk-1][i], SP[msk-1][i + (1 << (msk-1))]);
            }
        }
    }
public:
    SparseTable(const vector<T>& arr, const CMP& cmp){
        merge = cmp;
        build(arr);
    }
    T query(int l, int r){
        int len = r - l + 1;
        int lg = 31 - __builtin_clz(len);
        return merge(
            SP[lg][l],
            SP[lg][r - (1 << lg) + 1]
        );
        
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        ll ans = 0;
        SparseTable<int> s(arr, [](const int& a, const int& b){return a & b;});
        for(int i = 0; i < n; i++){
            int st = -1, end = -1;
            int l = i, r = n-1;;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(s.query(i, mid) <= k){
                    if (s.query(i, mid) == k)
                        st = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            l = i, r = n-1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if (s.query(i, mid) >= k){
                    if (s.query(i, mid) == k)
                        end = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            if (st != -1){
                ans+= 0LL + end - st + 1;
            }
        }
        return ans;

    }
};