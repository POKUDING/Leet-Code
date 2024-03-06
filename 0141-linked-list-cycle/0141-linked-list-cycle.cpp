const static auto _ = []{cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head) {
            if(head->val == INT_MAX) return true;
            head->val = INT_MAX;
            head = head->next;
        }
        return false;
    }
};