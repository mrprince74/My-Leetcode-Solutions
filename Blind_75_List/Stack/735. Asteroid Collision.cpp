//Problem Link: https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> st;
        for(int x: a){
            bool should_push = true;
            while(!st.empty()){
                if (x < 0 && st.back() > 0){
                if (st.back() == -x){
                    should_push = 0;
                    st.pop_back();
                    break;
                }
                else if (st.back() > -x){
                    should_push = 0;
                    break;
                }
                else if (st.back() < -x){
                    st.pop_back();
                }
                    
                }
                else
                    break;
            }
            if (should_push)
                st.push_back(x);
        }
        
        
        return st;
        
    }
};