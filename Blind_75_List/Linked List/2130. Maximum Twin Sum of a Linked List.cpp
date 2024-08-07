//Problem Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    ListNode* reversed(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur;
        ListNode* next = new ListNode(head->next->val);
        
        while(head){
            cur = new ListNode(head->val);
            cur->next = prev;
            prev = cur;
            cur = next;
            if (head->next)
            next = new ListNode(head->next->val);
            else
                break;
            
            head = head->next;
            
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        ListNode* rev = reversed(temp);
        int ans = 0;
        for(; rev && head; rev = rev->next, head = head->next){
            ans = max(ans, head->val + rev->val);
        }
        return ans;
        
    }
};