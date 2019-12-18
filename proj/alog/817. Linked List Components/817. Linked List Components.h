//
//  817. Linked List Components.h
//  leetcode
//
//  Created by andysheng on 2019/12/19.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _17__Linked_List_Components_h
#define _17__Linked_List_Components_h

#include "DataStructure.h"

namespace P817 {
    class Solution {
        public:
        int numComponents(ListNode* head, vector<int>& G) {
            unordered_set<int, bool> GMap;
            for (auto g: G) {
                GMap[g] = true;
            }
            int ret = 0;
            while (head) {
                if (GMap.find(head->val) != GMap.end()) {
                    ++ret;
                    while (head && GMap.find(head->val) != GMap.end()) {
                        head = head->next;
                    }
                } else {
                    head = head->next;
                }
            }
            return ret;
        }
    };
}
#endif /* _17__Linked_List_Components_h */
