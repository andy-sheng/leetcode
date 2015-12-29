class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> hashMap;
        map<int, int>::iterator tmp;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            tmp = hashMap.find(nums[i]);
            if (tmp == hashMap.end()) {
                hashMap.insert(make_pair(nums[i], i));
            } else {
                if (i - tmp->second <= k) {
                    return true;
                } else {
                    tmp->second = i;
                }
            }
        }
        return false;
    }
};