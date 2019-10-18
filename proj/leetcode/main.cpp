//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1104. Path In Zigzag Labelled Binary Tree.h"

int main(int argc, const char * argv[]) {
    
    for (int node: PathInZigzagLabelledBinaryTree::Solution().pathInZigZagTree(26)) {
        cout << node << endl;
    }
    
    
 
    return 0;
}
