from piece import Piece

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
        return "\u0332B\u0332 \u0332|"
