class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        prefix = strs[0]
        for str in strs:
            count = 0
            for i in range(min(len(prefix), len(str))):
                if prefix[i] == str[i]:
                    count += 1
                else:
                    break
            prefix = prefix[0:count]
        return prefix
