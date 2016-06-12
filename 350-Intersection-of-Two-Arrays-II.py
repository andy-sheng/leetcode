class Solution(object):
    def __init__(self):
        self.low = 0
        self.high = 0
        
    def binarySearch(self, arr, target):
        low = self.low
        high = self.high
        while low <= high:
            mid = low + (high - low) / 2
            if arr[mid] < target:
                low = mid + 1
            elif arr[mid] > target:
                high = mid - 1
            else:
                return mid
        return -1
            
        
    def intersect(self, nums1, nums2):
        if len(nums1) == 0 or len(nums2) == 0:
            return []
            
        result = []
        dict1 = {}
        dict2 = {}
        
        nums1.sort()
        nums2.sort()
        for num in nums1:
            if num in dict1:
                dict1[num] = dict1[num] + 1
            else:
                dict1[num] = 1
        for num in nums2:
            if num in dict2:
                dict2[num] = dict2[num] + 1
            else:
                dict2[num] = 1
            

        self.high = len(nums2) - 1
        
        lastNum = nums1[0] - 1
        for num in nums1:
            if lastNum != num:
                tmp = self.binarySearch(nums2, num)
                if tmp != -1:
                    self.low = tmp + 1
                    for i in range(0, min(dict1[num], dict2[num])):
                        result.append(num)
                lastNum = num
        return result
        