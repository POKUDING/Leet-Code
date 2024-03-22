const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int s = 0, e = vec.size() - 1;
        while(s < e)
            if(vec[s++] != vec[e--])
                return false;
        return true;
    }
};