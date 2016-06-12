class Solution(object):
    def __init__(self):
        self.low = 0
        self.length = 0
        
    def binarySearch(self, arr, target):
        high = self.length
        while self.low <= high:
            mid = self.low + (high - self.low) / 2
            if arr[mid] < target:
                self.low = mid + 1
            elif arr[mid] > target:
                high = mid - 1
            else:
                return mid
        return -1
            
        
    def intersection(self, nums1, nums2):
        if len(nums1) == 0 or len(nums2) == 0:
            return []
            
        result = []
        
        nums1.sort()
        nums2.sort()

        self.length = len(nums2) - 1
        
        lastNum = nums1[0] - 1
        for num in nums1:
            if lastNum != num:
                tmp = self.binarySearch(nums2, num)
                if tmp != -1:
                    self.low = tmp
                    result.append(num)
                lastNum = num
        return result
        