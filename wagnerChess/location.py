when the Board is told to move a piece, it checks the logic of the request, THEN
Updates the Piece-poiter inside the changing Locations.

class Location(object):

    letterMap={"A":[0,1,2,3,4,5,6,7],
               "B":[0,1,2,3,4,5,6],
               "C":[0,1,2,3,4,5],
               "D":[0,1,2,3,4],
               "E":[0,1,2,3],
               "F":[0,1,2],
               "G":[0,1],
               "H":[0]
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

    def placePiece(self,piece):
        self.piece=piece

    def clearPiece(self):
        self.piece=None

    
    def equals(self,location):
        if not isinstance(location,Location):
            raise Exception("not a Loation")

        return self.letterMap[self.letter]==self.letterMap[location.getLetter()] and self.number==location.getNumber()
