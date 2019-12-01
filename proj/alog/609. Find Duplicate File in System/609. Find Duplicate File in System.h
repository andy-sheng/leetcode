//
//  609. Find Duplicate File in System.h
//  leetcode
//
//  Created by andysheng on 2019/12/2.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _09__Find_Duplicate_File_in_System_h
#define _09__Find_Duplicate_File_in_System_h

#include "DataStructures.h"

namespace P609 {
    class Solution {
    public:
        vector<vector<string>> findDuplicate(vector<string>& paths) {
            unordered_map<string, vector<string>> map;
            for (string path: paths) {
                int spaceIndex = path.find(' ');
                string dir = path.substr(0, spaceIndex);

                do {
                    string::size_type contentStart = path.find('(', spaceIndex);
                    string::size_type contentEnd = path.find(')', contentStart);
                    string filename = path.substr(spaceIndex + 1, contentStart - spaceIndex - 1);
                    string content = path.substr(contentStart, contentEnd - contentStart + 1);
                    
                    if (map.find(content) == map.end()) {
                        map[content] = vector<string>();
                    }
                    map[content].push_back(dir + '/' + filename);
                    spaceIndex = path.find(' ', spaceIndex + 1);
                } while (spaceIndex > 0);
            }
            vector<vector<string>> ret;
            for (auto paths: map) {
                if (paths.second.size() > 1) {
                    ret.push_back(paths.second);
                }
            }
            return ret;
        }
    };
}

#endif /* _09__Find_Duplicate_File_in_System_h */
