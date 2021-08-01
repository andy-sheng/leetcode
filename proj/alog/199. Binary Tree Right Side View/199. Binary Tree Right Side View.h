//
//  199. Binary Tree Right Side View.h
//  leetcode
//
//  Created by andysheng on 2021/8/2.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _99__Binary_Tree_Right_Side_View_h
#define _99__Binary_Tree_Right_Side_View_h

#include "DataStructures.h"

namespace P199 {

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) { return ret; }
        vector<TreeNode> queue = {root};
        int nodeCntCur = 1;
        int nodeCntNext = 0;
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            if (node->left) {
                queue.push_back(node->left);
                ++nodeCntNext;
            }
            if (node->right) {
                queue.push_back(node->right);
                ++nodeCntNext;
            }
            queue.erase(queue.begin());
            --nodeCntCur;
            if (nodeCntCur == 0) {
                ret.push_back(node->val);
                nodeCntCur = nodeCntNext;
                nodeCntNext = 0;
            }
        }
        return ret;
    }
};

}
#endif /* _99__Binary_Tree_Right_Side_View_h */
