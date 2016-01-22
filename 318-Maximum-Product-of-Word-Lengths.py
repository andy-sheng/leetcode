class Solution(object):
    dic = {"z":0b1,"y":0b10,"x":0b100, "w":0b1000, "v":0b10000, "u":0b10000, "t":0b100000, "s":0b100000, "r":0b1000000, "q":0b10000000, "p":0b100000000, "o":0b1000000000, "n":0b10000000000, "m":0b100000000000, "l":0b1000000000000, "k":0b10000000000000, "j":0b100000000000000, "i":0b1000000000000000, "h":0b10000000000000000, "g":0b100000000000000000, "f":0b1000000000000000000, "e":0b10000000000000000000, "d":0b100000000000000000000, "c":0b1000000000000000000000, "b":0b10000000000000000000000, "a":0b100000000000000000000000}
    def getWordLength(self, words):
        results = []
        for word in words:
            results.append(len(word))
        return results

    def words2letter(self, words):
        results = []
        for word in words:
            tmp = 0
            for letter in word:
                tmp |= self.dic[letter]
            results.append(tmp)
        return results


    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        uncommenArr = []
        wordsLen = len(words)
        result = 0
        letters = self.words2letter(words)
        wordsLength = self.getWordLength(words)

        for i in range(wordsLen):
            for j in range(i + 1, wordsLen):
                if not letters[i] & letters[j]:
                    tmp = wordsLength[i] * wordsLength[j]
                    if tmp > result:
                        result = tmp
        return result
