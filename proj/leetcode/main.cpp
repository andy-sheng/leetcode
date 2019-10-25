//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1123. Lowest Common Ancestor of Deepest Leaves.h"

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
    cout << LowestCommonAncestorOfDeepestLeaves::Solution().lcaDeepestLeaves(root)->val << endl;
    
    
    
    return 0;
}
