//
//  92. Reverse Linked List II.h
//  leetcode
//
//  Created by andysheng on 2021/8/17.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _2__Reverse_Linked_List_II_h
#define _2__Reverse_Linked_List_II_h

namespace P92 {

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) { return head; }
        ListNode *fakeNode = new ListNode(), *appendNode = fakeNode, *firstNodeToReverse = NULL;
        int idx = 1;
        while (head) {
            ListNode *tmp = head->next;
            
            if (idx >= left && idx <= right) {
                if (idx == left) {
                    firstNodeToReverse = head;
                }
                
                head->next = appendNode->next;
                appendNode->next = head;
                if (idx == right) {
                    appendNode = firstNodeToReverse;
                }
            } else {
                head->next = appendNode->next;
                appendNode->next = head;
                appendNode = head;
            }
    
            head = tmp;
            ++idx;
        }
        return fakeNode->next;
    }
};
}
#endif /* _2__Reverse_Linked_List_II_h */
