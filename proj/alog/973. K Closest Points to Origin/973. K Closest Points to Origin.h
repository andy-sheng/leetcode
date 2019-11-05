//
//  973. K Closest Points to Origin.h
//  leetcode
//
//  Created by andysheng on 2019/11/5.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _73__K_Closest_Points_to_Origin_h
#define _73__K_Closest_Points_to_Origin_h
#include "DataStructures.h"
namespace KClosestPointsToOrigin {
    class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            vector<pair<int, int>> heap(K);
            for (int i = 0; i < K; ++i) {
                heap[i] = make_pair(pow(points[i][0], 2) + pow(points[i][1], 2), i);
            }
            makeHeap(heap);
            
            for (int i = K; i < points.size(); ++i) {
                int dis = pow(points[i][0], 2) + pow(points[i][1], 2);
                if (dis < heap[0].first) {
                    heap[0] = make_pair(dis, i);
                    adjustHeap(heap, 0);
                }
            }
            
            vector<vector<int>> ret(K);
            for (int i = 0; i < K; ++i) {
                ret[i] = points[heap[i].second];
            }
            return ret;
        }
        
        void makeHeap(vector<pair<int, int>> &heap) {
            for (int i = heap.size() - 1; i > -1; --i) {
                adjustHeap(heap, i);
            }
        }
        
        void adjustHeap(vector<pair<int, int>> &heap, int i) {
            pair<int, int> tmp = heap[i];
            for (int k = i * 2 + 1; k < heap.size(); k = 2 * k + 1) {
                if (k + 1 < heap.size() && heap[k].first < heap[k + 1].first) ++k;
                if (heap[k] > tmp) {
                    heap[i] = heap[k];
                    i = k;
                } else {
                    break;
                }
            }
            heap[i] = tmp;
        }
    };
}
#endif /* _73__K_Closest_Points_to_Origin_h */
