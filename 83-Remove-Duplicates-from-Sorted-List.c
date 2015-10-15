struct ListNode* deleteDuplicates(struct ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        struct ListNode *last = head, *current = head->next;
        while (current) {
            if (last->val == current->val) {
                last->next = current->next;
            } else {
                last = current;
            }
            current = current->next;
        }
        return head;
    }