//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "34. Find First and Last Position of Element in Sorted Array.h"

int main(int argc, const char * argv[]) {
    vector<int> input = {1};
    
    for (auto item: P34::Solution().searchRange(input, 1)) {
        cout << item <<" ";
    }
    return 0;
}
