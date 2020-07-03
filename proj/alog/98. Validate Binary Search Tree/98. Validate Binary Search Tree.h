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
    public:
        bool isValidBST(TreeNode* root) {
            long lastNodeValue = LONG_MIN;
            return isValidBST(root, lastNodeValue);
        }
        
        bool isValidBST(TreeNode* root, long &lastNodeValue) {

            if (!root) { return true; }
            if (root->left && !isValidBST(root->left, lastNodeValue)) { return false; }

            if (root->val <= lastNodeValue) { return false; }
            lastNodeValue = root->val;
            if (!root->right) {
                return true;
            }
            return isValidBST(root->right, lastNodeValue);
        }
    };
}
#endif /* _8__Validate_Binary_Search_Tree_h */
