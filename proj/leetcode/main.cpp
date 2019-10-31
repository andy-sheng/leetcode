//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "959. Regions Cut By Slashes.h"

int main(int argc, const char * argv[]) {
    
    vector<string> grid {"\\/\\ "," /\\/"," \\/ ","/ / "};
    std::cout << RegionsCutBySlashes::Solution().regionsBySlashes(grid) << std::endl;
    
    return 0;
}
