//
//  841. Keys and Rooms .h
//  leetcode
//
//  Created by andysheng on 2019/11/5.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _41__Keys_and_Rooms__h
#define _41__Keys_and_Rooms__h

#include "DataStructures.h"

namespace KeysAndRooms {
    class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            bool finished = false;
            set<int> visited {0};
            if (visited.size() == rooms.size()) {
                return true;
            }
            visitRoom(rooms, visited, 0, finished);
            
            return finished;
        }
        
        void visitRoom(vector<vector<int>> &rooms, set<int> &visited, int room, bool &finished) {
            if (finished) {
                return;
            }
            for (int key : rooms[room]) {
                
                if (visited.find(key) == visited.end()) {
                    visited.insert(key);
//                    cout << key << endl;
//                    cout << rooms.size() << " " << visited.size() << endl;
                    finished = (visited.size() == rooms.size());
                    visitRoom(rooms, visited, key, finished);
                }
                if (finished) {
                    return;
                }
            }
        }
    
    };
}
#endif /* _41__Keys_and_Rooms__h */
