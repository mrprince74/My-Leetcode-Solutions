class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int totalOR = 0;
        for(int num : nums)
            totalOR|= num;
        int n = nums.size();
        int ans = 0;
        for(int msk = 0; msk < (1 << n); msk++){
            int myOR = 0;
            for(int i = 0; i < n && myOR != totalOR; i++){
                if (msk & (1 << i))
                    myOR|= nums[i];
            }
            ans+= (myOR == totalOR);
        }
        return ans;
    }
};