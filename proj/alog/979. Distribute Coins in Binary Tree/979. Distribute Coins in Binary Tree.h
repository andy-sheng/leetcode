//
//  979. Distribute Coins in Binary Tree.h
//  leetcode
//
//  Created by andysheng on 2019/10/22.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _79__Distribute_Coins_in_Binary_Tree_h
#define _79__Distribute_Coins_in_Binary_Tree_h

namespace DistributeCoinsInBinaryTree {
    class Solution {
    public:
        int distributeCoins(TreeNode* root) {
            int cnt = 0;
            travel(root, cnt);
            return cnt;
        }
        
        int travel(TreeNode *root, int &cnt) {
            if (!root) return 0;
            
            int left = travel(root->left, cnt);
            int right = travel(root->right, cnt);
            
            cnt += abs(left) + abs(right);
            
            return left + right + root->val - 1;
        }
    };
}
#endif /* _79__Distribute_Coins_in_Binary_Tree_h */
