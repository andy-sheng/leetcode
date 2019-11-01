//
//  912. Sort an Array .h
//  leetcode
//
//  Created by andysheng on 2019/11/2.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _12__Sort_an_Array__h
#define _12__Sort_an_Array__h

namespace SortAnArray {
    class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            return nums;
        }
    };
}
#endif /* _12__Sort_an_Array__h */
