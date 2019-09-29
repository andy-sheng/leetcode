//
//  2. Add Two Numbers.h
//  leetcode
//
//  Created by andysheng on 2019/8/18.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef ___Add_Two_Numbers_h
#define ___Add_Two_Numbers_h

namespace AddTwoNumber {
    
     struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
    
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *curL1 = l1;
            ListNode *curL2 = l2;
            ListNode *retListHead = NULL, *retListCur = NULL;
            
            int carry = 0;
            while (curL1 && curL2) {
                int ret =  curL1->val + curL2->val + carry;
                carry = ret / 10;
                
                retListCur = appendNodeToList(retListCur, ret % 10);
                if (!retListHead)
                {
                    retListHead = retListCur;
                }
                
                curL1 = curL1->next;
                curL2 = curL2->next;
            }
            
            ListNode *remainList = !curL1 ? curL1 : curL2;
            while (remainList) {
                
                int ret =  remainList->val + carry;
                carry = ret / 10;
                
                retListCur = appendNodeToList(retListCur, ret % 10);
                if (!retListHead)
                {
                    retListHead = retListCur;
                }
                
                remainList = remainList->next;
            }
            
            while (carry) {
                retListCur = appendNodeToList(retListCur, carry % 10);
                if (!retListHead)
                {
                    retListHead = retListCur;
                }
                carry = carry / 10;
            }
            return retListHead;
        }
    private:
        ListNode* appendNodeToList(ListNode *listTail, int val)
        {
            ListNode *newNode = new ListNode(val);
            if (listTail)
            {
                listTail->next = newNode;
            }
            return newNode;
        }
    };
}

#endif /* ___Add_Two_Numbers_h */
