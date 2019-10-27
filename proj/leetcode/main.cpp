//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1110. Delete Nodes And Return Forest.h"

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<int> input {3,5};
    for (TreeNode *node : DeleteNodesAndReturnForest::Solution().delNodes(root, input)) {
        cout << node->val << endl;
    }
    
    return 0;
}
