//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1008. Construct Binary Search Tree from Preorder Traversal.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {4,2};
    ConstructBinarySearchTreeFromPreorderTraversal::Solution().bstFromPreorder(input);
 
    return 0;
}
