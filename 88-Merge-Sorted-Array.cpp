class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        long popBack = nums1.size() - m;
        while (popBack > 0) {
            nums1.pop_back();
            popBack--;
        }
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (i < m && nums1[i] < nums2[j]) {
                i++;
            }
            nums1.insert(nums1.begin() + i, nums2[j]);
            m++;
        }
    }
};
