//Problem Link: https://leetcode.com/problems/unique-number-of-occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count;
        for(int x: arr){
            if (count.count(x))
            count[x]++;
            else
                count[x] = 1;
        }
        int occ = 0;
        unordered_map<int,int> seen;
        for(auto [_, freq]: count){
            if (seen.count(freq)) return false;
            seen[freq] = 1;
        }
        return true;
    }
};