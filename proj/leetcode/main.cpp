//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1019. Next Greater Node In Linked List.h"


int main(int argc, const char * argv[]) {
    ListNode *root = new ListNode(2);
    root->next = new ListNode(1);
    root->next->next = new ListNode(5);
//    ListNode *root = new ListNode(1);
//    root->next = new ListNode(7);
//    root->next->next = new ListNode(5);
//    root->next->next->next = new ListNode(1);
//    root->next->next->next->next = new ListNode(9);
//    root->next->next->next->next->next = new ListNode(2);
//    root->next->next->next->next->next->next = new ListNode(5);
//    root->next->next->next->next->next->next->next = new ListNode(1);
    for (auto i: P1019::Solution().nextLargerNodes(root)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
