//
//  1769. Minimum Number of Operations to Move All Balls to Each Box.h
//  leetcode
//
//  Created by andysheng on 2021/7/20.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _769__Minimum_Number_of_Operations_to_Move_All_Balls_to_Each_Box_h
#define _769__Minimum_Number_of_Operations_to_Move_All_Balls_to_Each_Box_h

#include <vector>

using namespace std;

namespace P1769 {

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ret(boxes.size(), 0);
        int ballCount = 0;
        vector<int> ballsOnTheLeft(boxes.size() + 1, 0);
        for (int i = (int)boxes.size() - 1; i > -1; --i) {
            int box = boxes[i] - '0';
            ballCount += box;
            ballsOnTheLeft[i] = ballsOnTheLeft[i+1] + box;
            ret[0] += box * i;
        }
        for (int i = 1; i < boxes.size(); ++i) {
            ret[i] = ret[i - 1] + (ballCount - ballsOnTheLeft[i]) - ballsOnTheLeft[i];
        }
        
        return ret;
    }
};

}
#endif /* _769__Minimum_Number_of_Operations_to_Move_All_Balls_to_Each_Box_h */
