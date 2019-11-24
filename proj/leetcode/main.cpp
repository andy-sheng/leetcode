//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "983. Minimum Cost For Tickets.h"

int main(int argc, const char * argv[]) {
    
    vector<int> days {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs {2,7,15};
    cout << MinimumCostForTickets::Solution().mincostTickets(days, costs)<<endl;
    return 0;
}
