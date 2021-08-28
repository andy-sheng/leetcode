//
//  82. Remove Duplicates from Sorted List II.h
//  leetcode
//
//  Created by andysheng on 2021/8/28.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _2__Remove_Duplicates_from_Sorted_List_II_h
#define _2__Remove_Duplicates_from_Sorted_List_II_h

namespace P82 {

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *fakeHead = new ListNode(), *appendNode = fakeHead;
        fakeHead->next = head;
        while (head) {
            if (head->next && head->val == head->next->val) {
                int val = head->val;
                while (head && head->val == val) {
                    ListNode *next = head->next;
                    // delete head;
                    head = next;
                }
                appendNode->next = head;
            } else {
                appendNode = head;
                head = head->next;
            }
        }
        return fakeHead->next;
    }
};

}
#endif /* _2__Remove_Duplicates_from_Sorted_List_II_h */
