//
//  894. All Possible Full Binary Trees.h
//  leetcode
//
//  Created by andysheng on 2019/10/18.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _94__All_Possible_Full_Binary_Trees_h
#define _94__All_Possible_Full_Binary_Trees_h

#include <vector>
#include <unordered_map>
#include "DataStructures.h"
using namespace std;
namespace AllPossibleFullBinaryTrees {
    class Solution {
    private:
        unordered_map<int, vector<TreeNode *>> cache;
    public:
        vector<TreeNode *> allPossibleFBT(int N) {
            if (N % 2 == 0) return vector<TreeNode *>();

            if (cache.find(N) != cache.end()) return cache[N];
            
            if (N == 1) {
                cache[1] = vector<TreeNode *> {new TreeNode(0)};
                return vector<TreeNode *> {new TreeNode(0)};
            }
            
            

            vector<TreeNode *> ret;


            vector<TreeNode *> tmp = allPossibleFBT(N - 2);

            for (int i = 1; i < N; i += 2) {
                vector<TreeNode *> leftTrees = allPossibleFBT(i);
                vector<TreeNode *> rightTrees = allPossibleFBT(N - 1 - i);

                for (TreeNode *left: leftTrees) {
                    for (TreeNode *right: rightTrees) {
                        TreeNode *newRoot = new TreeNode(0);
                        newRoot->left = left;
                        newRoot->right = right;
                        ret.push_back(newRoot);
                    }
                }
            }
            if (cache.find(N) == cache.end()) {
                cache[N] = ret;
            }

            return ret;
        }
    };
}
#endif /* _94__All_Possible_Full_Binary_Trees_h */
