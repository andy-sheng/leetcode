class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bull = 0
        cow = 0
        secretArr = {'0':[],'1':[],'2':[],'3':[],'4':[],'5':[],'6':[],'7':[],'8':[],'9':[]}
        guessArr = {'0':[],'1':[],'2':[],'3':[],'4':[],'5':[],'6':[],'7':[],'8':[],'9':[]}
        for i in range(0, len(secret)):
            secretArr[secret[i]].append(i)
        for i in range(0, len(guess)):
            guessArr[guess[i]].append(i)
        for i in range(10):
            cow += min(len(secretArr[str(i)]), len(guessArr[str(i)]))
            bullTmp = 0
            for pos in secretArr[str(i)]:
                if pos in guessArr[str(i)]:
                    bullTmp += 1
            cow -= bullTmp
            bull += bullTmp
        return str(bull)+'A'+str(cow)+'B'


        
