from location import Location
from abc import ABCMeta, abstractmethod

class Piece(object):

    pieces=['king','queen','bishop','knight','rook','pawn']

    #location "B,3", for example
    #root: Player's root datastruct in RAM
    def __init__(self,location,root,piece,color):

        if piece not in Piece.pieces:
            raise Exception("invalid piece passed:",str(piece))
        
        self.root=root
        self.location=location
        self.piece=piece
        self.color=color
        self.location.setPiece(self)
        self.virgin=True#able to track is piece has been moved yet [rook,king,pawn]
        self.isPawn=False

    def unsex(self):
        self.virgin=True
        
    def sex(self):
        if self.virgin==True:
            firstTime=True
        else:
            firstTime=False
        self.virgin=False
        return firstTime
        

    def getPieceType(self):
        return self.piece
        
    def getColor(self):
        return self.color

    def getLocation(self):
        return self.location
    
    def changeLocation(self,newLoc):
        self.location=newLoc#update location pointer
        newLoc.setPiece(self)#update the Location's piece pointer

    #verify a piece of same color is not already present
    #return either None, or location parameter back to caller
    def checkNextLocation(self,location):
        if location==None:
            return None
        elif location.getPiece()==None:
            return location
        else:
            if location.getPiece().getColor()==self.color:
                return None
            elif self.isPawn and location.getPiece().getColor()!=self.color:
                return None
            else:
                return location
        
    #return location if enemy piece is present
    def isEnemyPresent(self,location):
        piece=location.getPiece()
        if piece==None:
            return None
        elif piece.color!=self.color:
            return location
        else:
            return None


    #call listMoves, then check each location for enemy piece, return [of pieces]
    def canThreatenList(self):
        retval=[]
        locations=self.listMoves()
        for l in locations:
            l=self.isEnemyPresent(l)
            if l!=None:
                retval.append(l.getPiece())

        return retval

            
    @abstractmethod    
    def listMoves(self):
        #given current location, return list of legal locations
        #return Locations[]
        print ("this needs to be over written by subclass.")


    @abstractmethod
    def toString(self):
        pass
