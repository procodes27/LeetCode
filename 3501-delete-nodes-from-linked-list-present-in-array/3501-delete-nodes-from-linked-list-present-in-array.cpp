class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (st.find(curr->val) != st.end()) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};