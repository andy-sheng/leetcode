class Solution(object):
    def binarySearch(self, arr, target):
        low = 0
        high = len(arr) - 1
        while low <= high:
            mid = low + (high - low) / 2
            if arr[mid] < target:
                low = mid + 1
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
        
        lastNum = nums1[0] - 1
        for num in nums1:
            if lastNum != num:
                if self.binarySearch(nums2, num) != -1:
                    result.append(num)
                lastNum = num
        return result