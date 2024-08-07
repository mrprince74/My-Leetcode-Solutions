//Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if (!fast->next)
            return nullptr;
        fast = fast->next->next;
        while(fast && fast->next){
                slow = slow->next;
                fast = fast->next;
                fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
        
    }
};