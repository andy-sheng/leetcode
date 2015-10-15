class Solution {
public:
    vector<ListNode*> record;
    bool hasCycle(ListNode *head) {
        ListNode* current = head, *last = NULL;
        while (current != NULL) {
            if (last != NULL && current == head) {
                return true;
            }
            last = current;
            current = current->next;
            last->next = head;
        }
        return false;
    }
    
};