//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "841. Keys and Rooms .h"

int main(int argc, const char * argv[]) {
    vector<vector<int>> input {{1},{2},{3}};
    cout << KeysAndRooms::Solution().canVisitAllRooms(input)<<endl;
    return 0;
}
