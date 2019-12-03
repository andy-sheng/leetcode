//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1105. Filling Bookcase Shelves.h"


int main(int argc, const char * argv[]) {
    vector<vector<int>> input {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << P1105::Solution().minHeightShelves(input, 4)<<endl;
    return 0;
}
