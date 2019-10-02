//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "707. Design Linked List.h"

int main(int argc, const char * argv[]) {
    
    DesignLinkedList::MyLinkedList myLinkedList();
    myLinkedList().addAtHead(1);
    myLinkedList().addAtTail(3);
    myLinkedList().addAtIndex(1, 2);
    std::cout << myLinkedList().get(1) << std::endl;
    myLinkedList().deleteAtIndex(0);
    myLinkedList().get(0);
    
    return 0;
}
