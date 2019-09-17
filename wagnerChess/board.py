from piece import Piece
from location import Location
#make the litter of Locations; they will know their UID on init
#Later we call a connect the Links function to interlink the Location Objects.

class Board(object):

    def __init__(self,args{}):

        self.board={}#holds the locations; use getBoard(), not root pointer
        self.root={"players":[],
                   "board":self}

        self.root["players"].append(Player("white",self.root))
        self.root["players"].append(Player("black",self.root))
        
        #update Location to track a Piece pointer!

        letters=Location.letterMap.keys()
        for l in letters:
            numbers=Location.letterMap[l]
            for n in numbers:
                index="%s,%d" % (l,n)
                self.board[index] = Location(l,n)


    def linkLocations(self):
        #The locations are linked together to form the board
        #8-way max, links from a given piece
        #min of 2 links
        for loc in self.board:
            loc.interconnect(self)

    def getBoard(self):
        return self.board
    
            
    def assignPiece(self,piece,location):
        location.placePiece()

    #updates the threat list for each piece
    #then loops through all parts to see which pose a threat to <piece>
    #return list of Piece objects currently threatending <piece>
    def checkForThreats(self,piece):
        #check for, and return a list of threat-pieces
        ret=[]
        
        return ret
