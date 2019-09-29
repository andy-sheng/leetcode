//
//  938. Range Sum of BST.h
//  leetcode
//
//  Created by andysheng on 2019/9/30.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _38__Range_Sum_of_BST_h
#define _38__Range_Sum_of_BST_h

#include "DataStructures.h"

namespace RangeSumOfBST {
    
    class Solution {
    public:
        int rangeSumBST(TreeNode* root, int L, int R) {
            if (!root) return 0;
            
            int ret = rangeSumBST(root->left, L, R);
            
            if (root->val >= L && root->val <= R) {
                ret += root->val;
            }
            
            ret += rangeSumBST(root->right, L, R);
            
            return ret;
        }
    };
    
}
#endif /* _38__Range_Sum_of_BST_h */
