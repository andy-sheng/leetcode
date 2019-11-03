//
//  1026. Maximum Difference Between Node and Ancestor.h
//  leetcode
//
//  Created by andysheng on 2019/11/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _026__Maximum_Difference_Between_Node_and_Ancestor_h
#define _026__Maximum_Difference_Between_Node_and_Ancestor_h

#include "DataStructures.h"

namespace MaximumDifferenceBetweenNodeAndAncester {
    class Solution {
    public:
        int maxAncestorDiff(TreeNode* root) {
            int ret = -1;
            travel(root, root->val, root->val, ret);
            return ret;
        }

        void travel(TreeNode* root, int smallest, int greatest, int &greatestDiff) {
            if (!root) return;
            greatestDiff = max(greatestDiff, abs(root->val - smallest));
            greatestDiff = max(greatestDiff, abs(root->val - greatest));
            travel(root->left,
                   min(smallest, root->val),
                   max(greatest, root->val),
                   greatestDiff);
            travel(root->right,
                   min(smallest, root->val),
                   max(greatest, root->val),
                   greatestDiff);
        }
    };
}
#endif /* _026__Maximum_Difference_Between_Node_and_Ancestor_h */
