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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *end = curr;
        for(int i = 0; i < n; ++i)
            end = end->next;
        while(end != nullptr) {
            prev = curr;
            curr = curr->next;
            end = end->next;
        }
        if(!prev)
            return curr->next;
        prev->next = curr->next;
        return head;
    }
};