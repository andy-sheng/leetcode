//
//  109. Convert Sorted List to Binary Search Tree.h
//  leetcode
//
//  Created by andysheng on 2020/6/9.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _09__Convert_Sorted_List_to_Binary_Search_Tree_h
#define _09__Convert_Sorted_List_to_Binary_Search_Tree_h

#include "DataStructures.h"

namespace P109 {
    class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            return sortedListToBST(head, NULL);
        }
        TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
            if (!head) { return NULL; }
            if (head == tail) { return new TreeNode(head->val); }
            ListNode *midPtr = head, *tailPtr = head;
            while (tailPtr != tail) {
                tailPtr = tailPtr->next;
                if (tailPtr == tail) {
                    break;
                }
                tailPtr = tailPtr->next;
                midPtr = midPtr->next;
            }
            TreeNode *rootNode = new TreeNode(midPtr->val);
            
            if (head != midPtr) {
                
                cout << "left " << head->val;
            }
            cout << " mid " << midPtr->val;
            if (midPtr != tail) {
                
                cout << " right " << (tail ? tail->val : -111);
            }
            cout << endl;
                
            if (head != midPtr) {
                rootNode->left = sortedListToBST(head, midPtr);
                
            }
            
            if (midPtr->next != tail) {
                rootNode->right = sortedListToBST(midPtr->next, tail);
                
            }
            
            return rootNode;
        }
    };
}
#endif /* _09__Convert_Sorted_List_to_Binary_Search_Tree_h */
