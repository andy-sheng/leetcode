//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "48. Rotate Image.h"

int main(int argc, const char * argv[]) {
    vector<vector<int>> input = {{1,2},{3,4}};
    P48::Solution().rotate(input);
    for (auto row: input) {
        for (auto item: row) {
            cout << item <<" ";
        }
        cout << endl;
    }
    return 0;
}
