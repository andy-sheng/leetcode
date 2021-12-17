//
//  47. Permutations II.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _7__Permutations_II_h
#define _7__Permutations_II_h

#include "DataStructures.h"

namespace P47 {

class Solution {
private:
    int size;
    vector<vector<int>> ret;
    vector<int> tmp;
    unordered_map<int, int> map;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        tmp = vector<int>(nums.size());
        size = nums.size();
        for (auto num: nums) {
            if (map.find(num) == map.end()) {
                map[num] = 0;
            }
            ++map[num];
        }
        doPermute(nums, 0);
        return ret;
    }
    void doPermute(vector<int>& nums, int slot) {
        if (slot == size) {
            ret.push_back(tmp);
            return;
        }
        for (auto kv: map) {
            if (kv.second == 0) {
                continue;
            }
            map[kv.first]--;
            tmp[slot] = kv.first;
            doPermute(nums, slot+1);
            map[kv.first]++;
        }
    }
};

}
#endif /* _7__Permutations_II_h */
