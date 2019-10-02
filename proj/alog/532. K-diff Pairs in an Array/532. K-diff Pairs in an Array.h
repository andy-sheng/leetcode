//
//  532. K-diff Pairs in an Array.h
//  leetcode
//
//  Created by andysheng on 2019/10/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _32__K_diff_Pairs_in_an_Array_h
#define _32__K_diff_Pairs_in_an_Array_h

#include <unordered_map>
#include <vector>

using namespace std;
namespace KDiffPairsInAnArray {
    class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            unordered_map <int, int> occuredNums;
            
            for (int i = 0; i < nums.size(); ++i) {
                ++occuredNums[nums[i]];
            }
            
            int ret = 0;
            unordered_map <int, int>::iterator iter;
            iter = occuredNums.begin();
            while (iter != occuredNums.end()) {
                if (k == 0 && iter->second > 1) {
                    ret += 1;
                } else if (k > 0 && occuredNums.find(iter->first + k) != occuredNums.end()) {
                    ++ret;
                }
                
                ++iter;
            }
            
            return ret;
        }
    };
}

#endif /* _32__K_diff_Pairs_in_an_Array_h */
