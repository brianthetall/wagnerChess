from piece import Piece

class Rook(Piece):

    def __init__(self,location,root,color):

        super(Rook,self).__init__(location,root,"rook",color)
        

    #return a list of valid Locations
    def listMoves(self):
        validMoves=[]
        #look North,East,South,West
        #if a piece exists on location of Different color, include the Location & stop traversing the direction

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
                                
        return validMoves



    def toString(self):
        return "\u0332R\u0332 \u0332|"
