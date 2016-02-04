import math
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        result = [1]

        if rowIndex == 0:
            return result
            
        n = rowIndex
        for i in range(int(math.ceil((float(rowIndex) + 1) / 2) - 1)):
            result.append(result[-1] * n / (rowIndex - n + 1))
            n -= 1
        if rowIndex % 2 == 0:
            result.extend(result[-2::-1])
        else:
            result.extend(result[::-1])
        return result
            