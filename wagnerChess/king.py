from piece import Piece

class King(Piece):

    def __init__(self,location,root,color):

        super(King,self).__init__(location,root,"king",color)
        pass

    def listMoves(self):
        validMoves=[]
        loc=self.checkNextLocation(self.location.getNorth())
        if loc!=None:
            validMoves.append(loc)
        loc=self.checkNextLocation(self.location.getWest())
        if loc!=None:
            validMoves.append(loc)
        loc=self.checkNextLocation(self.location.getSouth())
        if loc!=None:
            validMoves.append(loc)
        loc=self.checkNextLocation(self.location.getEast())
        if loc!=None:
            validMoves.append(loc)

        loc=self.checkNextLocation(self.location.getNorthWest())
        if loc!=None:
            validMoves.append(loc)
        loc=self.checkNextLocation(self.location.getSouthWest())
        if loc!=None:
            validMoves.append(loc)
        loc=self.checkNextLocation(self.location.getSouthEast())
        if loc!=None:
            validMoves.append(loc)
        loc=self.checkNextLocation(self.location.getNorthEast())
        if loc!=None:
            validMoves.append(loc)
        
            
        for move in validMoves:
            print("Legal Move:"+move.toString())
        return validMoves


    def toString(self):
        return "K "
