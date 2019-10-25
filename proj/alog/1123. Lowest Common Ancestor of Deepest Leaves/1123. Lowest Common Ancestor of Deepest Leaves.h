//
//  1123. Lowest Common Ancestor of Deepest Leaves.h
//  leetcode
//
//  Created by andysheng on 2019/10/26.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _123__Lowest_Common_Ancestor_of_Deepest_Leaves_h
#define _123__Lowest_Common_Ancestor_of_Deepest_Leaves_h

#include <vector>
#include "DataStructures.h"
using namespace std;
namespace LowestCommonAncestorOfDeepestLeaves {
    class Solution {
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
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
#endif /* _123__Lowest_Common_Ancestor_of_Deepest_Leaves_h */
