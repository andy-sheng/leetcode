//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "39. Combination Sum.h"

int main(int argc, const char * argv[]) {

    vector<int> input = {2,3,6,7};
    for (vector<int> ret: P39::Solution().combinationSum(input, 7)) {
        for (auto i: ret) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
