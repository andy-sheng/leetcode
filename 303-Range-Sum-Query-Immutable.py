class NumArray(object):
    nums = []
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums = []
        if  len(nums) == 0:
            return
        self.nums.append(nums[0])
        for n in range(1, len(nums)):
            self.nums.append(self.nums[n - 1] + nums[n])

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        if len(self.nums) == 0:
            return

        zero2j = self.nums[j]

        if i == 0:
            zero2i = 0;
        else:
            zero2i = self.nums[i-1]
        return zero2j - zero2i


# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.sumRange(1, 2)
