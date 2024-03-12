class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode **curr_head = &head;
        ListNode *curr_node;
        while(*curr_head) {
            curr_node = *curr_head;
            int sum_val = 0;
            while(curr_node) {
                sum_val += curr_node->val;
                if(sum_val == 0)
                    *curr_head = curr_node->next;
                curr_node = curr_node->next;
            }
            if(*curr_head)
                curr_head = &(*curr_head)->next;
        }
        return head;
    }
};