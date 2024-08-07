//Problem Link: https://leetcode.com/problems/odd-even-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return nullptr;
        int n = 0;
        auto temp = head;
        map<int,ListNode*> mp;
        while(temp){
            mp[n++] = temp;
            temp = temp->next;
        }
        ListNode* ans = new ListNode(mp[0]->val);
        auto ret = ans;
        for(int i = 2; i<n; i+=2){
            ans->next = new ListNode(mp[i]->val);
            ans = ans->next;
        }
        for(int i = 1; i<n; i+=2){
            ans->next = new ListNode(mp[i]->val);
            ans = ans->next;
        }
        return ret;
        
        
    }
};