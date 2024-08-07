//Problem Link: https://leetcode.com/problems/maximum-subsequence-score/

class Solution {
public:
    #define ll long long
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<ll, ll>> p;
        int n = nums1.size();
        for(int i = 0; i<n; i++){
            p.emplace_back(nums2[i], nums1[i]);
        }
        sort(rbegin(p), rend(p));
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll so_far = 0;
        ll ans = 0;
        int i = 0, j = 0;
        for(; j < k; j++){
            so_far += p[j].second;
            pq.push((ll) p[j].second);
        }
        ans = max(ans, so_far * p[j-1].first);
        while(j < n){
            int rem = pq.top();
            pq.pop();
            so_far -= rem;
            so_far += p[j].second;
            ans = max(ans, so_far * p[j].first);
            pq.push(p[j].second);
            i++, j++;
        }
    return ans;
        
        
    }
};