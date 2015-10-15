class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        int gap, aLong;
        ListNode *tmpA = headA;
        while (tmpA != NULL) {
            lengthA++;
            tmpA = tmpA->next;
        }
        
        ListNode *tmpB = headB;
        while (tmpB) {
            lengthB++;
            tmpB = tmpB->next;
        }
        
        gap = lengthA - lengthB;
        if (gap >= 0) {
            for (int i = 0; i < gap; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0;i < -gap; i++) {
                headB = headB->next;
            }
        }
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
        
    }
    
};