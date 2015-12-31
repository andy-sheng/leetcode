class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        strs = []
        letter2str = {"a":"", "b":"", "c":"", "d":"", "e":"", "f":"", "g":"", "h":"", "i":"", "j":"", "k":"", "l":"",
                      "m":"", "n":"", "o":"", "p":"", "q":"", "r":"", "s":"", "t":"", "u":"", "v":"", "w":"", "x":"",
                      "y":"", "z":""}
        words = str.split()
        if len(pattern) != len(words):
            return False
        for i in range(0, len(pattern)):
            if letter2str[pattern[i]] != "":
               if letter2str[pattern[i]] != words[i]:
                   return False
            elif words[i] not in strs:
                strs.append(words[i])
                letter2str[pattern[i]] = words[i]
            else:
                return False
        return True



        
