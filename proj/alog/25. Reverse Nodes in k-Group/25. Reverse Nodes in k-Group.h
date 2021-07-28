//
//  25. Reverse Nodes in k-Group.h
//  leetcode
//
//  Created by andysheng on 2021/7/29.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _5__Reverse_Nodes_in_k_Group_h
#define _5__Reverse_Nodes_in_k_Group_h

namespace P25 {

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode *cur = head;
        while (cur) {
            ++length;
            cur = cur->next;
        }
        
        ListNode *ret = new ListNode(0), *attachNode = ret;
        ListNode *oldListHead = new ListNode(0);
        oldListHead->next = head;
        ListNode *prev = ret;

        for (int i = 0; i + k <= length; i += k) {
            ListNode *firstNode = NULL;
            for (int j = 0; j < k; ++j) {

                ListNode *tmp = oldListHead->next;
                oldListHead->next = tmp->next;
                tmp->next = attachNode->next;
                attachNode->next = tmp;
                if (!firstNode) { firstNode = tmp; }
            }
            attachNode = firstNode;
        }
        attachNode->next = oldListHead->next;
        return ret->next;
    }
};

}
#endif /* _5__Reverse_Nodes_in_k_Group_h */
