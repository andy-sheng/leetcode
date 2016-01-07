class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return [];
        result = []
        tmp = str(nums[0])
        last = nums[0]
        for i in range(1, len(nums)):
            if nums[i] - last != 1:
                if str(last) != tmp:
                    tmp += '->' + str(last)
                result.append(tmp)
                tmp = str(nums[i])
            last = nums[i]
        if str(nums[len(nums) - 1]) != tmp:
            tmp += '->' + str(last)
        result.append(tmp)
        return result
                
