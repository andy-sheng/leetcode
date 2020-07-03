//
//  98. Validate Binary Search Tree.h
//  leetcode
//
//  Created by andysheng on 2020/7/4.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _8__Validate_Binary_Search_Tree_h
#define _8__Validate_Binary_Search_Tree_h

namespace P98 {
    class Solution {
    private:
        TreeNode *lastNode = NULL;
    public:
        bool isValidBST(TreeNode* root) {
            if (!root) { return true; }
            if (root->left && !isValidBST(root->left)) { return false; }
            if (lastNode && root->val <= lastNode->val) { return false; }
            lastNode = root;
            return isValidBST(root->right);
        }
    };
}
#endif /* _8__Validate_Binary_Search_Tree_h */
