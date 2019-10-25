//
//  951. Flip Equivalent Binary Trees.h
//  leetcode
//
//  Created by andysheng on 2019/10/26.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _51__Flip_Equivalent_Binary_Trees_h
#define _51__Flip_Equivalent_Binary_Trees_h

namespace FlipEquivalentBinaryTrees {
    class Solution {
    public:
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
            if (!root1 && !root2) {
                return true;
            }
            if (!root1 || !root2) {
                return false;
            }
            return (root1->val == root2->val)
                && ((flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
                    || (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)));
        }
    };
}
#endif /* _51__Flip_Equivalent_Binary_Trees_h */
