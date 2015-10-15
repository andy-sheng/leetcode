class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int flag[INT_MAX] = {0};
            for (int n = 0; n < nums.size(); n++) {
                flag[nums[n]]++;
            }
            for (int n = 0; n < INT_MAX; n++) {
                if (flag[n] == 1) {
                    return n;
                }
            }
            return 0;
        }
};
