//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1004. Max Consecutive Ones III.h"

int main(int argc, const char * argv[]) {
    vector<int> input {1,1,1,0,0,0,1,1,1,1,0};
    cout << MaxConsecutiveOnesIII::Solution().longestOnes(input, 2)<<endl;
    return 0;
}
