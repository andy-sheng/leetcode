class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0, lastBit, a = 0, b = 0;
        for (auto item : nums) aXorb ^= item;
        lastBit = (aXorb & (aXorb - 1)) ^ aXorb;
    
        for (auto item : nums) {
            if (item & lastBit) {
              a ^= item;
            } else {
              b ^= item;
            }
        }
        return vector<int>{a, b};
    }
};