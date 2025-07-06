class FindSumPairs {
    unordered_map<int,int> freq1, freq2;
    vector<int> nums1, nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1(nums1), nums2(nums2) {
        for(int num : nums1)
            freq1[num]++;
        for(int num : nums2)
            freq2[num]++;
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index]+= val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto [num,f] : freq1){
            if (freq2.count(tot - num))
                ans+= f * freq2[tot - num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */