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
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         vector<ListNode *> arr;
//         ListNode* tmp = head;
//         while(tmp) {
//             arr.push_back(tmp);
//             tmp = tmp->next;
//         }
//         tmp = head;
//         int s = 1, e = arr.size() - 1;
//         while(s <= e) {
//             tmp->next = arr[e--];
//             tmp = tmp->next;
//             if(s <= e) {
//                 tmp->next = arr[s++];
//                 tmp = tmp->next;
//             }
//         }
//         tmp->next = nullptr;
//     }
// };
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next, *prev = nullptr, *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr =next;
        }
        slow->next = nullptr;
        ListNode *front = head, *back = prev;
        while(front && back) {
            ListNode *front_next = front->next;
            ListNode *back_next = back->next;

            front->next = back;
            back->next = front_next;

            front = front_next;
            back = back_next;
        }
    }
};