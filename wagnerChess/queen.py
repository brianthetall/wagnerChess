from piece import Piece
from termcolor import colored

class Queen(Piece):

    def __init__(self,location,root,color):

        super(Queen,self).__init__(location,root,"queen",color)

    def listMoves(self):
        validMoves=[]

        tempLoc=self.location
        while True:
            #North:
            nextLoc=tempLoc.getNorth()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)

        tempLoc=self.location
        while True:
            #West:
            nextLoc=tempLoc.getWest()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)


        tempLoc=self.location
        while True:
            #South:
            nextLoc=tempLoc.getSouth()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)


        tempLoc=self.location
        while True:
            #East:
            nextLoc=tempLoc.getEast()
            if nextLoc==None:
                break
            tempLoc=self.checkNextLocation(nextLoc)
            if tempLoc==None:
                break
            else:
                validMoves.append(tempLoc)
        

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

        for move in validMoves:
            print("Legal Move: "+move.toString())
        return validMoves

        
    def toString(self):
        if self.color=="white":
            return colored("\u0332Q\u0332 |","white")
        else:
            return colored("\u0332Q\u0332 |","red")

