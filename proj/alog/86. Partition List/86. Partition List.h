//
//  86. Partition List.h
//  leetcode
//
//  Created by andysheng on 2021/8/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _6__Partition_List_h
#define _6__Partition_List_h
#include "DataStructures.h"

namespace P86 {

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *fakeHead1 = new ListNode(), tail1 = fakeHead1;
        ListNode *fakeHead2 = new ListNode(), tail2 = fakeHead2;
        while (head) {
            ListNode *tmp = head->next;
            if (head->val < x) {
                tail1->next = head;
                tail1 = head;
            } else {
                head->next = NULL;
                tail2->next = head;
                tail2 = head;
            }
            head = tmp;
        }
        tail1->next = fakeHead2->next;
        return fakeHead1->next;
    }
};

}
#endif /* _6__Partition_List_h */
