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
const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = nullptr;
        ListNode* next = head;
        while(next){
            head = next;
            next = head->next;
            head->next = tmp;
            tmp = head;
        }
        return head;
    }
};