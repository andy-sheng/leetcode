//
//  725. Split Linked List in Parts.h
//  leetcode
//
//  Created by andysheng on 2020/6/8.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _25__Split_Linked_List_in_Parts_h
#define _25__Split_Linked_List_in_Parts_h

#include "DataStructures.h"

namespace P725 {
    class Solution {
    public:
        vector<ListNode*> splitListToParts(ListNode* root, int k) {
            int cnt = 0;
            ListNode *ptr = root;
            while (ptr) {
                ++cnt;
                ptr = ptr->next;
            }
            
            vector<ListNode *> ret;
            ret.push_back(root);
            int specialCnt = k > cnt ? 0 : cnt % k;
            int subListLen = k > cnt ? 1 : cnt / k;
            ptr = root;
            int tmpLen = 1;
            while (ptr && ret.size() < k) {
                if ((ret.size() <= specialCnt && tmpLen == subListLen + 1)
                    || (ret.size() > specialCnt && tmpLen == subListLen)) {
                    ListNode *next = ptr->next;
                    ptr->next = NULL;
                    ptr = next;
                    ret.push_back(ptr);
                    tmpLen = 1;
                } else {
                    ptr = ptr->next;
                    ++tmpLen;
                }
            }
            while(ret.size() != k) {
                ret.push_back(NULL);
            }
            return ret;
        }
    };
}
#endif /* _25__Split_Linked_List_in_Parts_h */
