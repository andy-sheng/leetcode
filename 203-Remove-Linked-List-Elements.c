/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head) return head;
    struct ListNode*cur = head->next, *last = head;
    while (cur) {
        if (cur->val == val) { // remove
            last->next = cur->next;
        } else {
            last = cur;
        }
        cur = cur->next;
    }
    return head->val == val ? head->next : head;
}
