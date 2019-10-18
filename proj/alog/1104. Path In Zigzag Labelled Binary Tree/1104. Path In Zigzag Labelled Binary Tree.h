//
//  1104. Path In Zigzag Labelled Binary Tree.h
//  leetcode
//
//  Created by andysheng on 2019/10/19.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _104__Path_In_Zigzag_Labelled_Binary_Tree_h
#define _104__Path_In_Zigzag_Labelled_Binary_Tree_h
#include <vector>
#include <deque>
using namespace std;

namespace PathInZigzagLabelledBinaryTree {
    class Solution {
    public:
        vector<int> pathInZigZagTree(int label) {
            deque<int> ret;
            
            nodeInLayer(0, 0, label, ret);
            
            return vector<int>(ret.begin(), ret.end());
        }
        
        int nodeInLayer(int layer, int cnt, int target, deque<int> &ret) {
            int curLayerNodeCnt = (1 << layer);
            if (cnt + curLayerNodeCnt >= target) {
                // target is in this layer
                ret.push_front(target);
                return target;
            }
            int node = nodeInLayer(layer + 1, cnt + curLayerNodeCnt, target, ret);
            
            // 父子之间的公式 
            int nodeInThisLayer = (curLayerNodeCnt + cnt) - (node - (curLayerNodeCnt + cnt) - 1) / 2;
            
            ret.push_front(nodeInThisLayer);
            
            return nodeInThisLayer;
        }
    };
}
#endif /* _104__Path_In_Zigzag_Labelled_Binary_Tree_h */
