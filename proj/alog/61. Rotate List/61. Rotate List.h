//
//  61. Rotate List.h
//  leetcode
//
//  Created by andysheng on 2020/6/29.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _1__Rotate_List_h
#define _1__Rotate_List_h

namespace P61 {
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (k == 0 || !head) { return head; }
            int len = 0;
            ListNode *curPtr = head;
            while (curPtr) {
                ++len;
                curPtr = curPtr->next;
            }
            k = k % len;
            
            if (k == 0) { return head; }
            
            ListNode *fastPtr = head, *slowPtr = head;
            while (k) {
                fastPtr = fastPtr->next;
                --k;
            }

            while (fastPtr->next) {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            
            ListNode *retHead = slowPtr->next;
            slowPtr->next = NULL;
            curPtr = retHead;
            while (curPtr->next) {
                curPtr = curPtr->next;
            }
            curPtr->next = head;
            
            return retHead;
        }
    };
}
#endif /* _1__Rotate_List_h */
