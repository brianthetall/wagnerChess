from location import Location
from abc import ABCMeta, abstractmethod

class Piece(object):

    pieces=['king','queen','bishop','knight','rook','pawn']

    #location "B,3", for example
    #root: Player's root datastruct in RAM
    def __init__(self,location,root,piece):

        if piece not in Piece.pieces:
            raise Exception("invalid piece passed:",str(piece))
        
        self.root=root
        self.location=location
        self.piece=piece
        self.location.setPiece(self)

    @abstractmethod    
    def listMoves(self):
        #given current location, return list of legal locations
        #return Locations[]
        print ("this needs to be over written by subclass.")


    @abstractmethod
    def toString(self):
        pass
