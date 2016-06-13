/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    struct ListNode* tmp = head->next;
    
    head->next = tmp->next;
    tmp->next = head;
    head = tmp;
    
    struct ListNode* front = head->next, *back;
    
    while (true) {
        if (front == NULL || front->next == NULL || front->next->next == NULL) {
            return head;
        }
        back = front->next->next;
        tmp = front->next;
        front->next = back;
        tmp->next = back->next;
        back->next = tmp;
        front = tmp;
    }
}