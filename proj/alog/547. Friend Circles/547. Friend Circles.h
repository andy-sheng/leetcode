//
//  547. Friend Circles.h
//  leetcode
//
//  Created by andysheng on 2019/12/9.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _47__Friend_Circles_h
#define _47__Friend_Circles_h

namespace P547 {
    class UnionFind {
    private:
        vector<int> arr;
        vector<int> rank;
    public:
        UnionFind(int n);
        int find(int x);
        void Union(int x, int y);
        bool isConnected(int x, int y);
    };

    UnionFind::UnionFind(int n) {
        arr = vector<int>(n);
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
    }

    int UnionFind::find(int x) {
        if (arr[x] != x) {
            arr[x] = find(arr[x]);
        }
        return arr[x];
    }

    void UnionFind::Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[x] > rank[y]) {
            arr[y] = x;
            rank[x] += rank[y];
        } else {
            arr[x] = y;
            rank[y] += rank[x];
        }
    }

    bool UnionFind::isConnected(int x, int y) {
        return find(x) == find(y);
    }

    class Solution {
    public:
        int findCircleNum(vector<vector<int>>& M) {
            UnionFind unionFind((int)M.size());
            for (int i = 0; i < M.size(); ++i) {
                for (int j = i + 1; j < M.size(); ++j) {
                    unionFind.Union(i, j);
                }
            }
            
            unordered_set<int> ret;
            for (int i = 0; i < M.size(); ++i) {
                ret.insert(i);
            }
            return ret.size();
        }
    };
}
#endif /* _47__Friend_Circles_h */
