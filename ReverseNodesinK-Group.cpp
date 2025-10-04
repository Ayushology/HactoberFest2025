class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: check if we have at least k nodes
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) return head;  // not enough nodes, return as is

        // Step 2: reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: connect with recursive call for rest
        head->next = reverseKGroup(curr, k);

        return prev; // new head after reversing k nodes
    }
};
