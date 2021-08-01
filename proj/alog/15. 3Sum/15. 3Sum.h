//
//  15. 3Sum.h
//  leetcode
//
//  Created by andysheng on 2021/7/30.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _5__3Sum_h
#define _5__3Sum_h

#include "DataStructures.h"

using namespace std;
namespace P15 {

class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
       // (x, y, z) x <= y <= z
       sort(nums.begin(), nums.end());
       vector<vector<int>> ret;
       for (int xPos = 0; xPos < (int)nums.size() - 2; ++xPos) {
           if (nums[xPos] > 0) break;
           if (xPos > 0 && nums[xPos] == nums[xPos-1]) continue;
           int yPos = xPos + 1;
           int zPos = nums.size() - 1;
           while (yPos < zPos) {
               int sum = nums[xPos] + nums[yPos] + nums[zPos];
               if (sum == 0) {
                   ret.push_back({nums[xPos], nums[yPos], nums[zPos]});
                   while (yPos < zPos && nums[yPos] == nums[yPos + 1]) ++yPos;
                   ++yPos;
                   while (yPos < zPos && nums[zPos] == nums[zPos - 1]) --zPos;
                   --zPos;
               } else if (sum > 0) {
                   --zPos;
               } else {
                   ++yPos;
               }
           }
       }
       return ret;
    }
     
};

}
#endif /* _5__3Sum_h */
