//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "986. Interval List Intersections.h"

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> A {{14,16}};
    vector<vector<int>> B {{7,13},{16,20}};
    
    for (vector<int> ret : IntervalListIntersections::Solution().intervalIntersection(A, B)) {
        cout << ret[0] << " " << ret[1] << endl;
    }
    
    return 0;
}
