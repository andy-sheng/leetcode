#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int m = nums.size();
        map<int, bool> tmp;
        for (int i = 0; i < m; i++) {
            if (tmp.find(nums[i]) == tmp.end()) {
                tmp.insert(pair<int, bool> (nums[i], true));
            } else {
                return true;
            }
        }
        return false;
    }
    
};