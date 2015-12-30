/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* nodeBeforeN = head, *cur = head;
    while (n != 0) {
        cur = cur->next;
        n--;
    }
    if (!cur) {
        return head->next;
    }
    while (cur && cur->next) {
        cur= cur->next;
        nodeBeforeN = nodeBeforeN->next;
    }


    nodeBeforeN->next = nodeBeforeN->next->next;
    return head;

}
