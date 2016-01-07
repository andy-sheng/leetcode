class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        while low < high:
            mid = (low + high) >> 1
            if isBadVersion(mid):
                high = mid
            else:
                low = mid + 1
        return low
