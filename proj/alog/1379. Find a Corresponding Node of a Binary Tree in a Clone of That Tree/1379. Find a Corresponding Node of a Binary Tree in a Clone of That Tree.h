//
//  1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree.h
//  leetcode
//
//  Created by andysheng on 2021/7/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _379__Find_a_Corresponding_Node_of_a_Binary_Tree_in_a_Clone_of_That_Tree_h
#define _379__Find_a_Corresponding_Node_of_a_Binary_Tree_in_a_Clone_of_That_Tree_h

#include "DataStructures.h"

namespace P1379 {

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) { return NULL; }
        if (original == target) { return cloned; }
        TreeNode *ret = getTargetCopy(original->left, cloned->left, target);
        if (ret) { return ret; }
        return getTargetCopy(original->right, cloned->right, target);
    }
};

}
#endif /* _379__Find_a_Corresponding_Node_of_a_Binary_Tree_in_a_Clone_of_That_Tree_h */
