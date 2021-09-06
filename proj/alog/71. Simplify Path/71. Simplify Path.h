//
//  71. Simplify Path.h
//  leetcode
//
//  Created by andysheng on 2021/9/7.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _1__Simplify_Path_h
#define _1__Simplify_Path_h

#include "DataStructures.h"

namespace P71 {

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        vector<string> components;
        int dirBegin = 0;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                string dir = path.substr(dirBegin + 1, i - dirBegin - 1);
                if (dir == ".") {
                } else if (dir == "..") {
                    if (components.size() > 0) components.pop_back();
                } else if (dir.size() > 0) {
                    components.push_back(dir);
                }
                dirBegin = i;
            }
        }
        string ret = "";
        for (auto component: components) {
            ret += "/" + component;
        }
        return ret.size() == 0 ? "/" : ret;
    }
};

}
#endif /* _1__Simplify_Path_h */
