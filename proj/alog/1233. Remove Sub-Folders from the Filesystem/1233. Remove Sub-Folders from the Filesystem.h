//
//  1233. Remove Sub-Folders from the Filesystem.h
//  leetcode
//
//  Created by andysheng on 2019/12/29.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _233__Remove_Sub_Folders_from_the_Filesystem_h
#define _233__Remove_Sub_Folders_from_the_Filesystem_h

#include "Datastructures.h"

namespace P1233 {
    class Solution {
    public:
        struct TrieTreeNode  {
                int count;
                int pass;
                TrieTreeNode *node[27];
            };
            
            vector<string> removeSubfolders(vector<string>& folder) {
                TrieTreeNode *root = new TrieTreeNode();
                for (auto item : folder) {
                    TrieTreeNode *tmp = root;
                    for (char c : item) {
                        tmp->pass++;
                        if (c >= 'a' && c <= 'z') {
                            if (!tmp->node[c - 'a']) {
                                tmp->node[c - 'a'] = new TrieTreeNode();
                            }
                            tmp = tmp->node[c - 'a'];
                        } else {
                            if (!tmp->node[26]) {
                                tmp->node[26] = new TrieTreeNode();
                            }
                            tmp = tmp->node[26];
                        }
                    }
                    tmp->count++;
                }
                vector<string> ret;
                travel(ret, root, "");
                return ret;
            }
            
            void travel(vector<string> &ret, TrieTreeNode *root, string tmp) {
                int isFolder = false;
                if (root->count > 0) {
                    ret.push_back(tmp);
                    isFolder = true;
                }
                for (int i = 0; i < 27; ++i) {
                    if (i == 26) {
                        if (root->node[26] && !isFolder) {
                            tmp.push_back('/');
                            travel(ret, root->node[26], tmp);
                            tmp.pop_back();
                        }
                    } else if (root->node[i]) {
                        tmp.push_back(i + 'a');
                        travel(ret, root->node[i], tmp);
                        tmp.pop_back();
                    }
                }
            }
    };
}
#endif /* _233__Remove_Sub_Folders_from_the_Filesystem_h */
