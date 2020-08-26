from piece import Piece
from termcolor import colored

class Bishop(Piece):
    
    def __init__(self,location,root,color):

        super(Bishop,self).__init__(location,root,"bishop",color)


        
    def listMoves(self):
        validMoves=[]

        #look NE,NW,SW,SE
        tempLoc=self.location
        while True:
            #NorthEast:
            nextLoc=tempLoc.getNorthEast()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)
                if tempLoc.getPiece()!=None:
                    break
                
        tempLoc=self.location
        while True:
            #NorthWest:
            nextLoc=tempLoc.getNorthWest()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)
                if tempLoc.getPiece()!=None:
                    break

        tempLoc=self.location
        while True:
            #SouthWest:
            nextLoc=tempLoc.getSouthWest()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)
                if tempLoc.getPiece()!=None:
                    break

        tempLoc=self.location
        while True:
            #SouthEast:
            nextLoc=tempLoc.getSouthEast()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)
                if tempLoc.getPiece()!=None:
                    break
                
        for move in validMoves:
            print("Legal Move: "+move.toString())

        return validMoves



    def toString(self):
        if self.color=="white":
            return colored("\u0332B\u0332 |","white")
        else:
            return colored("\u0332B\u0332 |","red")

