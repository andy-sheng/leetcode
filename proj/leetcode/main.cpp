//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "950. Reveal Cards In Increasing Order.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {17,13,11,2,3,5,7};
    for (int i : RevealCardsInIncreasingOrder::Solution().deckRevealedIncreasing(input)) {
        cout << i <<endl;
    }
 
    return 0;
}
