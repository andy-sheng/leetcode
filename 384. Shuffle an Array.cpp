class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        srand(time(0));
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>result = this->nums;
        for(int i = result.size(); i > 1; i--) {
            int pos = rand() % i;
            swap(result[pos], result[i - 1]);
        }
        return result;
    }
};