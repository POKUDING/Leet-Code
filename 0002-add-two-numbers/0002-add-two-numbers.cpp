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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int tmp = 0;
        int val1, val2;
        ListNode *rtn = new ListNode();
        ListNode *currptr = rtn;

        while (l1 || l2 || tmp)
        {
            val1 = 0;
            val2 = 0;
            if (l1)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            tmp += val1 + val2;
            cout << val1 << " " << val2 << "\n";
            currptr->next = new ListNode(tmp % 10);
            currptr = currptr->next;
            tmp /= 10;
        }
        return rtn->next;
    }
};