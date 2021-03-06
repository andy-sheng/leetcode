//
//  1094. Car Pooling.h
//  leetcode
//
//  Created by andysheng on 2019/12/4.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _094__Car_Pooling_h
#define _094__Car_Pooling_h

#include "DataStructures.h"

namespace P1049 {
    class Solution {
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            int location[1001];
            memset(location, 0, 1001 * sizeof(int));
            for (auto trip: trips) {
                location[trip[1]] += trip[0];
                location[trip[2]] -= trip[0];
            }
            int load = 0;
            for (int i = 1; i < 1001; ++i) {
                load += location[i];
                if (load > capacity) {
                    return false;
                }
            }
            return true;
        }
    };
    bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    class Solution2 {
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            vector<pair<int, int>> locations;
            for (vector<int>trip: trips) {
                locations.push_back(make_pair(trip[1], trip[0]));
                locations.push_back(make_pair(trip[2], -trip[0]));
            }
            
            sort(locations.begin(), locations.end(), compare);
            
            int load = locations.front().second;
            int currentLocation = locations.front().first;
            for (int i = 1; i < locations.size(); ++i) {
                pair<int, int> location = locations[i];
                if (location.first != currentLocation) {
                    if (load > capacity) {
                        return false;
                    }
                    currentLocation = location.first;
                }
                load += location.second;
            }
            return true;
        }
    };
}
#endif /* _094__Car_Pooling_h */
