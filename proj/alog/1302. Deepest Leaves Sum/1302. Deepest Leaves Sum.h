//
//  1302. Deepest Leaves Sum.h
//  leetcode
//
//  Created by andysheng on 2020/5/31.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _302__Deepest_Leaves_Sum_h
#define _302__Deepest_Leaves_Sum_h

namespace P1302 {
    class Solution {
    public:
        int deepestLeavesSum(TreeNode* root) {
            int depth = 0;
            return doTravesal(root, depth);
        }
        int doTravesal(TreeNode* root, int &depth) {
            if (!root) return 0;
            
            ++depth;
            if (!root->left && !root->right) {
                return root->val;
            }
            int leftDepth = depth + 1;
            int leftSum = doTravesal(root->left, leftDepth);
            int rightDepth = depth + 1;
            int rightSum = doTravesal(root->right, rightDepth);
            if (leftDepth == rightDepth) {
                depth = leftDepth;
                return leftSum + rightSum;
            } else if (leftDepth > rightDepth) {
                depth = leftDepth;
                return leftSum;
            } else {
                depth = rightDepth;
                return rightSum;
            }
        }
    };
}

#endif /* _302__Deepest_Leaves_Sum_h */
