//
//  DataStructures.h
//  leetcode
//
//  Created by andysheng on 2019/9/30.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef DataStructures_h
#define DataStructures_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif /* DataStructures_h */
