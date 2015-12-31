class Solution(object):
    def readStr(self,string):
        result = ""
        num = string[0]
        count = 0
        for i in range(0, len(string)):
            if (string[i] == num):
                count += 1
            else:
                result += str(count) + num
                num = string[i]
                count = 1
        result += str(count) + num
        return result

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        string = "1"
        for i in range(1, n):
            string = self.readStr(string)
        return string
