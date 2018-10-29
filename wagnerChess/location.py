class Location(object):

    self.letterMap={"A":[0],
                    "B":[-1,1],
                    "C":[-1,0,1],
                    "D":[-2,-1,1,2],
                    "E":[-2,-1,0,1,2],
                    "F":[-3,-2,-1,1,2,3],
                    "G":[-3,-2,-1,0,1,2,3],
                    "H":[-4,-3,-2,-1,1,2,3,4],
                    "I":[-3,-2,-1,0,1,2,3],
                    "J":[-3,-2,-1,1,2,3],
                    "K":[-2,-1,0,1,2],
                    "L":[-2,-1,1,2],
                    "M":[-1,0,1],
                    "N":[-1,1],
                    "O":[0]
    }
                    
    def __init__(self,letter,number):
        
        if letter not in self.letterMap.keys():
            raise Exception("invalid letter: %s" % letter)
        self.letter=letter

        if number not in self.letterMap[letter]:
            raise Exception("invalid number: %s not in %s" % (number,self.letterMap[letter]))
        self.number=number

        self.piece=None


    def getLetter(self):
        return letter

    def getNumber(self):
        return number
        
    def equals(self,location):
        if not isinstance(location,Location):
            raise Exception("not a Loation")

        return self.letterMap[self.letter]==self.letterMap[location.getLetter()] and self.number==location.getNumber()
