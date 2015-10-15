class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long int total = 1;
        int flag = 0;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                total *= nums[i];
            } else {
                flag++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0 && flag == 0) {
                result.push_back(total / nums[i]);
            } else if(nums[i] == 0 && flag == 1) {
                result.push_back(total);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
};