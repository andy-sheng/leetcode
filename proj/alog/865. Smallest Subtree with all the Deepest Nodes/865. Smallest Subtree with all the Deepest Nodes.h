//
//  865. Smallest Subtree with all the Deepest Nodes.h
//  leetcode
//
//  Created by andysheng on 2019/11/17.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _65__Smallest_Subtree_with_all_the_Deepest_Nodes_h
#define _65__Smallest_Subtree_with_all_the_Deepest_Nodes_h
#include "DataStructures.h"
namespace SmallestSubtreeWithAllTheDeppestNodes {
    class Solution {
    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            vector<TreeNode*> possiblePath, curPath;
            int depthest = 0;
            travel(root, possiblePath, curPath, depthest);
            return possiblePath.back();
        }

        void travel(TreeNode* root,
                    vector<TreeNode*> &possiblePath,
                    vector<TreeNode*> &curPath,
                    int &deepest) {
            if (!root) {
                return;
            }
            curPath.push_back(root);
            if (!root->left && !root->right) {
                // leaf
                if (curPath.size() > deepest) {
                    // new deepest, delete all node in possible path
                    deepest = curPath.size();
                    possiblePath.erase(possiblePath.begin(), possiblePath.end());
                    possiblePath.insert(possiblePath.begin(), curPath.begin(), curPath.end());
                } else if (curPath.size() == deepest) {
                    for (int i = possiblePath.size() - 1; i > -1 && possiblePath[i] != curPath[i]; --i) {
                        possiblePath.pop_back();
                    }
                }
            } else {
                travel(root->left, possiblePath, curPath, deepest);
                travel(root->right, possiblePath, curPath, deepest);
            }
            curPath.pop_back();
        }
    };
}
#endif /* _65__Smallest_Subtree_with_all_the_Deepest_Nodes_h */
