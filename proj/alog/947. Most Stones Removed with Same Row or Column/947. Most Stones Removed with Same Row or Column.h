//
//  947. Most Stones Removed with Same Row or Column.h
//  leetcode
//
//  Created by andysheng on 2019/12/28.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _47__Most_Stones_Removed_with_Same_Row_or_Column_h
#define _47__Most_Stones_Removed_with_Same_Row_or_Column_h

#include "DataStructures.h"

namespace P947 {
    class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            int treeCount = 0;
            vector<bool> visited(stones.size(), false);
            for (int i = 0; i < stones.size(); ++i) {
                if (!visited[i]) {
                    ++treeCount;
                    visited[i] = true;
                    mark(stones, visited, i);
                }
            }
            return stones.size() - treeCount;
//            Algorithm::UnionFind unionFind(20000);
//            for (auto stone : stones) {
//                unionFind.Union(stone.front(), stone.back() + 10000);
//            }
//            unordered_set<int> treeRoots;
//            for (auto stone : stones) {
//                int root = unionFind.find(stone[0]);
//                if (treeRoots.find(root) == treeRoots.end()) {
//                    treeRoots.insert(root);
//                }
//            }
//            return stones.size() - treeRoots.size();
        }
        void mark(vector<vector<int>>& stones, vector<bool> &vistied, int fromStone) {
            for (int i = 0; i < stones.size(); ++i) {
                if (!vistied[i] && (stones[i][0] == stones[fromStone][0] || stones[i][1] == stones[fromStone][1])) {
                    vistied[i] = true;
                    mark(stones, vistied, i);
                }
            }
        }
    };
}
#endif /* _47__Most_Stones_Removed_with_Same_Row_or_Column_h */
