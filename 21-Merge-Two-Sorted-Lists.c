struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        struct ListNode *newHead = NULL, *current = NULL;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (newHead == NULL) {
                    newHead = l1;
                    current = l1;
                    l1 = l1->next;
                    newHead->next = NULL;
                } else {
                    current->next = l1;
                    current = current->next;
                    l1 = l1->next;
                }
            } else {
                if (newHead == NULL) {
                    newHead = l2;
                    current = l2;
                    l2 = l2->next;
                    newHead->next = NULL;
                } else {
                    current->next = l2;
                    current = current->next;
                    l2 = l2->next;
                }
            }
        }
        if (l1) {
            current->next = l1;
        } else {
            current->next = l2;
        }
        return newHead;
    }