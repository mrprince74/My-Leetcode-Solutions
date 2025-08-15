class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        for(int num : fruits){
            bool good = false;
            for(int &b : baskets){
                if (b >= num){
                    good = true;
                    b = -1;
                    break;
                }
            }
            ans+= !good;
        }
        return ans;
    }
};