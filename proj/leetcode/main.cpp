//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "79. Word Search.h"

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> input = {
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'}
    };
    cout << P79::Solution().exist(input, "AAAAAAAAAAAAAAB") <<endl;
    
    
    return 0;
}
