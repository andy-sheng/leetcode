//
//  1019. Next Greater Node In Linked List.h
//  leetcode
//
//  Created by andysheng on 2019/12/4.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _019__Next_Greater_Node_In_Linked_List_h
#define _019__Next_Greater_Node_In_Linked_List_h

#include "DataStructures.h"

namespace P1019 {

    class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            vector<int> unsolvedNodeIndex; // index, val
            vector<int> ret;
            int index = 0;
            if (!head) return ret;
            while (head->next) {
                while (!unsolvedNodeIndex.empty() && unsolvedNodeIndex.back().second < head->next->val) {
                    ret[unsolvedNodeIndex.back().first] = head->next->val;
                    unsolvedNodeIndex.pop_back();
                }
                if (head->next->val > head->val) {
                    ret.push_back(head->next->val);
                } else {
                    ret.push_back(0);
                    unsolvedNodeIndex.push_back(make_pair(index, head->val));
                }
                // debug
                for (auto item: unsolvedNodeIndex) {
                    cout << item.first << endl;
                }
                cout << "------------" << endl;
                
                ++index;
                head = head->next;
            }
            ret.push_back(0);
            return ret;
        }
       
    };
}
#endif /* _019__Next_Greater_Node_In_Linked_List_h */
