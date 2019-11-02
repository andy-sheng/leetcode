//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "889. Construct Binary Tree from Preorder and Postorder Traversal.h"

int main(int argc, const char * argv[]) {
    
    vector<int> pre {1,2,4,5,3,6,7};
    vector<int> post {4,5,2,6,7,3,1};
    ConstructBinaryTreeFromPreorderAndPostorderTraversal::Solution().constructFromPrePost(pre, post);
    
    return 0;
}
