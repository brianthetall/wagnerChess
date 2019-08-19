from piece import Piece
from location import Location
from player import Player


class Board(object):

    def __init__(self):

        self.board=[]
        
        #update Location to track a Piece pointer!

        letters=Location.letterMap.keys()
        for l in letters:
            numbers=Location.letterMap[l]
            for n in numbers:
                self.board.append( Location(l,n) )                


    def assignPiece(self,piece,location):
        location.placePiece()


    #updates the threat list for each piece
    #then loops through all parts to see which pose a threat to <piece>
    #return list of Piece objects currently threatending <piece>
    def checkForThreats(self,piece):
        #check for, and return a list of threat-pieces
        ret=[]
        what is the O() of this question?
         
        
        return ret


                            
