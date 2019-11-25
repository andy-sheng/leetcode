//
//  1090. Largest Values From Labels.h
//  leetcode
//
//  Created by andysheng on 2019/11/26.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _090__Largest_Values_From_Labels_h
#define _090__Largest_Values_From_Labels_h
#include "DataStructures.h"
namespace P1090 {
    bool compare(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
    class Solution {
    public:
        int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
            vector<pair<int, int>> arr(labels.size());
            unordered_map<int, int> map;
            for (int i = 0; i < labels.size(); ++i) {
                arr[i] = make_pair(labels[i], values[i]);
            }
            sort(arr.begin(), arr.end(), compare);
            int ret = 0;
            for (int i = 0; i < arr.size() && num_wanted > 0; ++i) {
                if (map.find(arr[i].first) == map.end() || map[arr[i].first] < use_limit) {
                    map[arr[i].first] = map.find(arr[i].first) == map.end() ? 1 : map[arr[i].first] + 1;
                    ret += arr[i].second;
                    --num_wanted;
                }
            }
            return ret;
        }
    };
    
}
#endif /* _090__Largest_Values_From_Labels_h */
