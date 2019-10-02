//
//  707. Design Linked List.h
//  leetcode
//
//  Created by andysheng on 2019/10/2.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _07__Design_Linked_List_h
#define _07__Design_Linked_List_h

namespace DesignLinkedList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class MyLinkedList {
    private:
        ListNode *listHead;
    public:
        MyLinkedList() {
            listHead = NULL;
        }
        
        int get(int index) {
            int ret = -1;
            ListNode *curNode = listHead;
            while (curNode) {
                if (index == 0) {
                    ret = curNode->val;
                    break;
                }
                curNode = curNode->next;
                --index;
            }
            return ret;
        }
        
        void addAtHead(int val) {
            ListNode *newNode = new ListNode(val);
            newNode->next = listHead;
            listHead = newNode;
        }
        
        void addAtTail(int val) {
            if (!listHead) {
                addAtHead(val);
            } else {
                ListNode *tailNode = listHead;
                while (tailNode->next) {
                    tailNode = tailNode->next;
                }
                
                ListNode *newNode = new ListNode(val);
                tailNode->next = newNode;
            }
            
        }
        
        void addAtIndex(int index, int val) {
            if (index <= 0) {
                addAtHead(val);
            } else {
                ListNode *newNode = new ListNode(val);
                
                ListNode *curNode = listHead;
                while (curNode) {
                    if (index == 1) {
                        break;
                    }
                    curNode = curNode->next;
                    --index;
                }
                
                if (curNode) {
                    newNode->next = curNode->next;
                    curNode->next = newNode;
                }
            }
            
            
        }
        
        void deleteAtIndex(int index) {
            if (index == 0) {
                ListNode *newHead = listHead->next;
                delete listHead;
                listHead = newHead;
            } else if (listHead) {
                ListNode *curNode = listHead;
                while (curNode->next) {
                    if (index == 1) {
                        ListNode *delNode = curNode->next;
                        curNode->next = delNode->next;
                        delete delNode;
                        break;
                    }
                    curNode = curNode->next;
                    --index;
                }
            }
            
        }
    };
}
#endif /* _07__Design_Linked_List_h */
