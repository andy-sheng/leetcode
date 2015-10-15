class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* current = head->next, *last = head;
        head->next = NULL;
        while (current != NULL) {
            ListNode* tmp = current->next;
            current->next = last;
            last = current;
            current = tmp;
        }
        return last;
    }
};