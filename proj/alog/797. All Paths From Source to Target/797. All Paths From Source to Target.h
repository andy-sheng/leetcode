//
//  797. All Paths From Source to Target.h
//  leetcode
//
//  Created by andysheng on 2019/10/17.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _97__All_Paths_From_Source_to_Target_h
#define _97__All_Paths_From_Source_to_Target_h

#include <vector>

using namespace std;
namespace AllPathsFromSourceToTarget {
    class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> ret;
            vector<int> path;
            allPathsSourceTarget(graph, ret, path, 0, (int)graph.size() - 1);
            return ret;
        }
        
        void allPathsSourceTarget(vector<vector<int>> &graph,
                                  vector<vector<int>> &ret,
                                  vector<int>         &path,
                                  int                  from,
                                  int                  to) {
            if (from == to) {
                path.push_back(from);
                ret.push_back(vector<int> (path.begin(), path.end()));
                path.pop_back();
                return;
            }
            path.push_back(from);
            for (int i = 0; i < graph[from].size(); ++i) {
                allPathsSourceTarget(graph, ret, path, graph[from][i], (int)graph.size() - 1);
            }
            path.pop_back();
        }
    };
}
#endif /* _97__All_Paths_From_Source_to_Target_h */
