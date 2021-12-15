//
//  39. Combination Sum.h
//  leetcode
//
//  Created by andysheng on 2021/12/16.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _9__Combination_Sum_h
#define _9__Combination_Sum_h

#include "DataStructures.h"

namespace P39 {

class Solution {
private:
    int size;
    vector<int> tmp;
    vector<vector<int>> ret;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        size = candidates.size();
        doCombinationSum(candidates, 0, target);
        return ret;
    }
    void doCombinationSum(vector<int>& candidates, int index, int target) {
        if (target < 0 || index >= size) {
            return;
        }
        if (target == 0) {
            ret.push_back(tmp);
            return;
        }
        tmp.push_back(candidates[index]);
        doCombinationSum(candidates, index, target - candidates[index]);
        tmp.pop_back();
        doCombinationSum(candidates, index+1, target);
    }
};

}
#endif /* _9__Combination_Sum_h */
