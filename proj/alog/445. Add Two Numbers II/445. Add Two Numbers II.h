//
//  445. Add Two Numbers II.h
//  leetcode
//
//  Created by andysheng on 2020/6/7.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _45__Add_Two_Numbers_II_h
#define _45__Add_Two_Numbers_II_h

#include "DataStructures.h"

namespace P445 {
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int diff = 0;
            ListNode *l1Ptr = l1, *l2Ptr = l2;
            while (l1Ptr || l2Ptr) {
                if (l1Ptr) {
                    l1Ptr = l1Ptr->next;
                } else {
                    --diff;
                }
                if (l2Ptr) {
                    l2Ptr = l2Ptr->next;
                } else {
                    ++diff;
                }
            }
            int carry = 0;
            ListNode *head = addTwoNumbers(l1, l2, diff, carry);
            if (carry > 0) {
                ListNode *newHead = new ListNode(carry);
                newHead->next = head;
                head = newHead;
            }
            return head;
        }
        
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int align, int &carry) {
            if (!l1 && !l2) { return NULL; }
            int tmpCarry = 0;
            int curNodeSum = 0;
            ListNode *tmpNode = NULL;
            if (align == 0) {
                tmpNode = addTwoNumbers(l1->next, l2->next, align, tmpCarry);
                curNodeSum = tmpCarry + l1->val + l2->val;
            } else if (align > 0) {
                tmpNode = addTwoNumbers(l1->next, l2, align - 1, tmpCarry);
                curNodeSum = tmpCarry + l1->val;
            } else {
                tmpNode = addTwoNumbers(l1, l2->next, align + 1, tmpCarry);
                curNodeSum = tmpCarry + l2->val;
            }
            carry = curNodeSum / 10;
            ListNode *newHead = new ListNode(curNodeSum % 10);
            newHead->next = tmpNode;
            return newHead;
        }
    };
}
#endif /* _45__Add_Two_Numbers_II_h */
