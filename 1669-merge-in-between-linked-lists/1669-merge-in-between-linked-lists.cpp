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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prefixList = list1;
        ListNode* suffixList;
        int idx = 0;
        while(++idx < a)
            prefixList = prefixList->next;
        suffixList = prefixList->next;
        while(idx++ <= b)
            suffixList = suffixList->next;
        prefixList->next = list2;
        while(prefixList->next)
            prefixList = prefixList->next;
        prefixList->next = suffixList;
        return list1;
    }
};