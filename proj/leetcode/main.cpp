//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1161. Maximum Level Sum of a Binary Tree.h"

int main(int argc, const char * argv[]) {
    

    TreeNode *root = new TreeNode(1);
    
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    
    root->right = new TreeNode(0);
    
    
    cout << MaximumLevelSumOfABinaryTree::Solution().maxLevelSum(root) << endl;
    
 
    return 0;
}
