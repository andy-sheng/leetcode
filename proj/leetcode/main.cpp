//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "535. Encode and Decode TinyURL.h"

int main(int argc, const char * argv[]) {
    
    EncodeAndDecodeTinyURL::Solution solution;
    for (int i = 0; i < 10000; ++i) {
        string longUrl = solution.transformInt2String(i);
        string shortUrl = solution.encode(longUrl);
        string decodeUrl = solution.decode(shortUrl);
        std::cout << longUrl << std::endl <<  shortUrl << std::endl << decodeUrl << std::endl;
        
    }
    
    
    
    
    
    return 0;
}
