//
//  430. Flatten a Multilevel Doubly Linked List.h
//  leetcode
//
//  Created by andysheng on 2020/6/7.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _30__Flatten_a_Multilevel_Doubly_Linked_List_h
#define _30__Flatten_a_Multilevel_Doubly_Linked_List_h

#include "DataStructures.h"

namespace P430 {
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
    };
    class Solution {
    public:
        Node* flatten(Node* head) {
            Node* cur;
            Node* res = NULL;
            Node* curRes = NULL;
            
            std::stack<Node*> nodeToBePro;
            nodeToBePro.push(head);
            
            while (!nodeToBePro.empty())
            {
                cur = nodeToBePro.top();
                nodeToBePro.pop();
                if (cur->next != NULL)
                {
                    nodeToBePro.push(cur->next);
                }
                
                if (cur->child != NULL)
                {
                    nodeToBePro.push(cur->child);
                }

                if (res == NULL)
                {
                    res = cur;
                    res->child = NULL;
                    res->next = NULL;
                    res->prev = NULL;
                    curRes = res;
                }
                else
                {
                    cur->prev = curRes;
                    curRes->next = cur;
                    curRes->next->next = NULL;
                    curRes = curRes->next;
                    curRes->child = NULL;
                }
                
            }
        return res;
        }
    };
//    class Solution {
//    public:
//        Node* flatten(Node* head) {
//            pair<Node *, Node *> tmp = doFlatten(head);
//            return tmp.first;
//        }
//
//        pair<Node *, Node *> doFlatten(Node* head) {
//            Node *curPtr = head, *lastPtr = NULL;
//            while (curPtr) {
//                if (curPtr->child) {
//                    pair<Node *, Node *> childPtrs = doFlatten(curPtr->child);
//                    curPtr->child = NULL;
//
//                    if (curPtr->next) {
//                        curPtr->next->prev = childPtrs.second;
//                    }
//                    childPtrs.second->next = curPtr->next;
//                    curPtr->next = childPtrs.first;
//                    childPtrs.first->prev = curPtr;
//
//                    lastPtr = childPtrs.second;
//                    curPtr = childPtrs.second->next;
//                } else {
//                    lastPtr = curPtr;
//                    curPtr = curPtr->next;
//                }
//            }
//            return make_pair(head, lastPtr);
//        }
//    };
}
#endif /* _30__Flatten_a_Multilevel_Doubly_Linked_List_h */
