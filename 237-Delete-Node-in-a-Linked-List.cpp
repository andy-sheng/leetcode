class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* current = node;
        while (current->next != NULL) {
            current->val = current->next->val;
            if (current->next->next == NULL) {
                current->next = NULL;
                return;
            }
            current = current->next;
        }
    }
    
};