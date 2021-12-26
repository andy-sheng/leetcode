//
//  23. Merge k Sorted Lists.h
//  leetcode
//
//  Created by andysheng on 2021/12/26.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Merge_k_Sorted_Lists_h
#define _3__Merge_k_Sorted_Lists_h

#include "DataStructures.h"

namespace P23 {

class Solution {
private:
    vector<ListNode*> lists;
    int endIndex;
public:
    void adjustHeap(int index) {
        if (lists[index] == NULL) {
            while (endIndex >= 0 && lists[endIndex] == NULL) --endIndex;
            if (endIndex < 0) return;
            swap(lists[index], lists[endIndex]);
            while (endIndex >= 0 && lists[endIndex] == NULL) --endIndex;
            if (endIndex < 0) return;
        }
        if (endIndex < 0) return;
        int begin = index;
        int end = endIndex;
        ListNode *tmp = lists[begin];
        int targetPos = begin;
        for (int i = begin * 2 + 1; i <= end; i = i * 2 + 1) {
            if (i + 1 <= end && lists[i + 1]->val < lists[i]->val) ++i;
            if (lists[i]->val < tmp->val) {
                lists[targetPos] = lists[i];
                targetPos = i;
            } else {
                break;
            }
        }
        lists[targetPos] = tmp;
    }

    void makeHeap() {
        for (int i = endIndex - 1; i >= 0; --i) {
            adjustHeap(i);
        }
    }

    ListNode *pop()
    {
        ListNode *retPtr = lists[0];
        if (retPtr) {
            lists[0] = lists[0]->next;
            adjustHeap(0);
        }
        return retPtr;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        this->lists = lists;
        this->endIndex = lists.size() - 1;
        
        while (endIndex >= 0 && lists[endIndex] == NULL) --endIndex;
        
        makeHeap();
        
        ListNode *retPtr = new ListNode(NULL), *curPtr = retPtr;
        while (ListNode *node = pop()) {

            curPtr->next = node;
            curPtr = node;
        }
        
        return retPtr->next;
    }
};

}

#endif /* _3__Merge_k_Sorted_Lists_h */
