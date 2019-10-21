//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1222. Queens That Can Attack the King.h"

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> queens {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king {0,0};
    for (vector<int> queen : QueensThatCanAttackTheKing::Solution().queensAttacktheKing(queens, king)) {
        cout << queen[0] << " " << queen[1] << endl;
    }
    
    return 0;
}
