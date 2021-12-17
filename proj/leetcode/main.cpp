//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "31. Next Permutation.h"

int main(int argc, const char * argv[]) {
    vector<int> input = {1};
    P31::Solution().nextPermutation(input);
    for (auto item: input) {
        cout << item <<" ";
    }
    return 0;
}
