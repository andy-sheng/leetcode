//
//  1325. Delete Leaves With a Given Value.h
//  leetcode
//
//  Created by andysheng on 2020/6/4.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _325__Delete_Leaves_With_a_Given_Value_h
#define _325__Delete_Leaves_With_a_Given_Value_h

#include "DataStructures.h"

namespace P1325 {
    class Solution {
    public:
        TreeNode* removeLeafNodes(TreeNode* root, int target) {
            if (!root) { return NULL; }
            if (!root->left) {
                root->left = removeLeafNodes(root->left, target);
            }
            if (!root->right) {
                root->right = removeLeafNodes(root->right, target);
            }
            if (!root->left && !root->right && root->val == target) {
                free
                return NULL;
            }
            return root;
        }
    };
}
#endif /* _325__Delete_Leaves_With_a_Given_Value_h */
