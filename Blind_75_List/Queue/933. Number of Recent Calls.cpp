//Problem Link: https://leetcode.com/problems/number-of-recent-calls
class RecentCounter {    
public:
    vector<int> a;
    int last_l = 0;
    RecentCounter() {
    }
    
    int ping(int t) {
        a.push_back(t);
        int ans = 0;
        int r_idx = a.size() - 1;
        int& l_idx = last_l;
        while(l_idx < r_idx){
            if (a[l_idx] >= (t - 3000)){
                break;
            }
            l_idx++;
        }
        return r_idx - l_idx + 1;
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */