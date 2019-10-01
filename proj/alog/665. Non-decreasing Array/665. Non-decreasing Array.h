//
//  665. Non-decreasing Array.h
//  leetcode
//
//  Created by andysheng on 2019/10/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _65__Non_decreasing_Array_h
#define _65__Non_decreasing_Array_h
#include <vector>
using namespace std;
namespace NonDecreasingArray {
    class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            bool hasDecreasingOccured = false;
            
            for (int slow = 0, fast = 1; fast < nums.size();) {
                if (nums[fast] < nums[slow]) { // decreasing
                    if (hasDecreasingOccured) {
                        return false;
                    }
                    hasDecreasingOccured = true;
                    
                    if (fast + 1 < nums.size() && nums[fast + 1] < nums[slow]) { // remove the slow
                        if (slow == 0) {
                            ++slow;
                            ++fast;
                        } else {
                            --slow;
                        }
                    } else { // remove the fast
                        ++fast;
                    }
                } else {
                    slow = fast;
                    ++fast;
                }
                
            }
            
            return true;
        }
    };
}

#endif /* _65__Non_decreasing_Array_h */
