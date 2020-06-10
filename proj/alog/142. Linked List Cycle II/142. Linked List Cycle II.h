//
//  142. Linked List Cycle II.h
//  leetcode
//
//  Created by andysheng on 2020/6/11.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _42__Linked_List_Cycle_II_h
#define _42__Linked_List_Cycle_II_h

#include "DataStructures.h"

namespace P142 {
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *slowPtr = head, *fastPtr = head;
            while (fastPtr) {
                fastPtr = fastPtr->next;
                if (fastPtr == slowPtr) {
                    slowPtr = head;
                    fastPtr = fastPtr->next;
                    while (fastPtr != slowPtr) {
                        fastPtr = fastPtr->next;
                        slowPtr = slowPtr->next;
                    }
                    return fastPtr;
                }
                if (!fastPtr) {
                    break;
                }
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            return NULL;
        }
    };
}
#endif /* _42__Linked_List_Cycle_II_h */
