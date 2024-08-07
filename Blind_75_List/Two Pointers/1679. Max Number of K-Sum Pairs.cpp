//Problem Link: https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:      
int maxOperations(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, j = n -1;
    int ans = 0;
    sort(nums.begin(), nums.end());
    while (i < j)  {
        if (nums[i] + nums[j] > k) {
            j--;
        }
        else if (nums[i] + nums[j] < k) {
            i++;
        }
        else if (nums[i]+ nums[j] == k) {
            ans++;
            // if (i+1 >= j-1) break;
            i++; j--;
        }
    }
    return ans;

    }
};