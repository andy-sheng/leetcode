//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "969. Pancake Sorting.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {3,2,4,1};
    for (int i : PanCakeSorting::Solution().pancakeSort(input)) {
        cout << i << endl;
    }
    
    return 0;
}
