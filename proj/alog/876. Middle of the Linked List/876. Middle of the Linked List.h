//
//  876. Middle of the Linked List.h
//  leetcode
//
//  Created by andysheng on 2020/6/1.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _76__Middle_of_the_Linked_List_h
#define _76__Middle_of_the_Linked_List_h

namespace P876 {
    class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode *fastPtr = head;
            ListNode *slowPtr = head;
            while (true) {
                if (!fastPtr) {
                    break;
                }
                fastPtr = fastPtr->next;
                if (!fastPtr) {
                    break;
                }
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            return slowPtr;
        }
    };
}
#endif /* _76__Middle_of_the_Linked_List_h */
