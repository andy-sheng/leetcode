//
//  1111. Maximum Nesting Depth of Two Valid Parentheses Strings.h
//  leetcode
//
//  Created by andysheng on 2019/10/20.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _111__Maximum_Nesting_Depth_of_Two_Valid_Parentheses_Strings_h
#define _111__Maximum_Nesting_Depth_of_Two_Valid_Parentheses_Strings_h

#include <vector>
using namespace std;
namespace MaximumNestingDepthOfTwoValidParenthese {
    class Solution {
    public:
        vector<int> maxDepthAfterSplit(string seq) {
            vector<int> ret(seq.size(), 0);
            
            int depth = 0;
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] == '(') {
                    ++depth;
                    ret[i] = depth % 2;
                } else {
                    ret[i] = depth % 2;
                    --depth;
                }
                
            }
            
            return ret;
        }
    };
}
#endif /* _111__Maximum_Nesting_Depth_of_Two_Valid_Parentheses_Strings_h */
