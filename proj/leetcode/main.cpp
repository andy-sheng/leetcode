//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "40. Combination Sum II.h"

int main(int argc, const char * argv[]) {

    vector<int> input = {2,5,2,1,2};
    for (vector<int> ret: P40::Solution().combinationSum2(input, 5)) {
        for (auto i: ret) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
