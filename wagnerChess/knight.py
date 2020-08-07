from piece import Piece

class Knight(Piece):

    def __init__(self,location,root,color):

        super(Knight,self).__init__(location,root,"knight",color)


    def listMoves(self):
        validMoves=[]

        #checkNorth + east/west        
        tempLoc=self.location
        try:
            loc=tempLoc.getNorth().getNorth().getEast()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        try:
            loc=tempLoc.getNorth().getNorth().getWest()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
                
            

        #checkWest + north/south
        try:
            loc=tempLoc.getWest().getWest().getNorth()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        try:
            loc=tempLoc.getWest().getWest().getSouth()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        
        #checkSouth + east/west
        try:
            loc=tempLoc.getSouth().getSouth().getEast()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        try:
            loc=tempLoc.getSouth().getSouth().getWest()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        
        #checkEast + north/south        
        try:
            loc=tempLoc.getEast().getEast().getNorth()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        try:
            loc=tempLoc.getEast().getEast().getSouth()
            loc=self.checkNextLocation(loc)
            if loc!=None:
                validMoves.append(loc)
        except Exception as e:
            pass
        
        for move in validMoves:
            print("Legal Move:"+move.toString())
        return validMoves



    def toString(self):
        return "\u0332N\u0332 \u0332|"
