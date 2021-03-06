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
    bool compare(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> cntMap;
            
            for (int num: nums) {
                if (cntMap.find(num) == cntMap.end()) {
                    cntMap[num] = 1;
                } else {
                    ++cntMap[num];
                }
            }
            vector<pair<int, int>> heap(k);
            unordered_map<int, int>::iterator it = cntMap.begin();
            for (int i = 0; i < k; ++i) {
                heap[i] = make_pair(it->first, it->second);
                ++it;
            }
            
            make_heap(heap.begin(), heap.end(), compare);
            
            for (;it != cntMap.end(); ++it) {
                if (heap[0].second < it->second) {
                    pair<int, int> p = make_pair(it->first, it->second);
                    int targetPos = 0;
                    for (int i = targetPos * 2 + 1; i < heap.size(); i = i * 2 + 1) {
                        if (i + 1 < heap.size() && compare(heap[i], heap[i + 1])) i += 1;
                        if (heap[i].second < p.second) {
                            heap[targetPos] = heap[i];
                            targetPos = i;
                        } else {
                            break;
                        }
                    }
                    heap[targetPos] = p;
                }
            }
            vector<int> ret;
            for (pair<int, int> p: heap) {
                ret.push_back(p.first);
            }
            return ret;
        }
    };
}
#endif /* _73__K_Closest_Points_to_Origin_h */
