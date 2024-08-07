//Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

// Sol 1: (Intended Solution)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int num : nums){
            q.push(num);
        }
        while(--k){
            q.pop();
        }
        return q.top();
    }
};

// Sol 2 : (The straightforward  solution though not the intended)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),greater<int>());
        return nums[k-1];
        
    }
};
