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
    void reorderList(ListNode* head) {
        vector<ListNode *> arr;
        ListNode* tmp = head;
        while(tmp) {
            arr.push_back(tmp);
            tmp = tmp->next;
        }
        tmp = head;
        int s = 1, e = arr.size() - 1;
        while(s <= e) {
            tmp->next = arr[e--];
            tmp = tmp->next;
            if(s <= e) {
                tmp->next = arr[s++];
                tmp = tmp->next;
            }
        }
        tmp->next = nullptr;
    }
};