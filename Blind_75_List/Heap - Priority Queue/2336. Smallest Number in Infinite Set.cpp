//Problem Link: https://leetcode.com/problems/smallest-number-in-infinite-set/

class SmallestInfiniteSet {
priority_queue<int, vector<int>, greater<int>> q;
map<int,bool> exist;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i<= 1002; i++){
            exist[i] = 1;
            q.push(i);
        }
    }
    
    int popSmallest() {
        int x = q.top();
        exist[x] = 0;
        q.pop();
        return x;
    }
    
    void addBack(int num) {
        if (!exist[num])
        q.push(num);
        exist[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */