//
//  40. Combination Sum II.h
//  leetcode
//
//  Created by andysheng on 2021/12/16.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _0__Combination_Sum_II_h
#define _0__Combination_Sum_II_h

#include "DataStructures.h"

namespace P40 {

class Solution {
private:
    int size;
    vector<int> tmp;
    vector<vector<int>> ret;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        size = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0,target);
        
        return ret;
    }
    void backtrack(vector<int>& candidates, int index, int target) {
        if (target == 0) {
            ret.push_back(tmp);
            return;
        }
        if (target < 0) {
            return;
        }
        int i = index;
        while (i < candidates.size()) {
            tmp.push_back(candidates[i]);
            backtrack(candidates, i+1, target - candidates[i]);
            tmp.pop_back();
            ++i;
            while (i < candidates.size() && candidates[i] == candidates[i-1]) ++i;
        }
    }
};

}
#endif /* _0__Combination_Sum_II_h */
