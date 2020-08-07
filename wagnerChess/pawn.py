from piece import Piece

class Pawn(Piece):

    def __init__(self,location,root,color):

        super(Pawn,self).__init__(location,root,"pawn",color)

        self.secondSquare=True
        self.isPawn=True#used by checkNextLocation

    def isEnemyPresent(self,location):
        piece=location.getPiece()
        if piece==None:
            return None
        elif piece.color!=self.color:
            return location
        else:
            return None

    def listMoves(self):
        validMoves=[]

        if self.color=="white":
            tempLoc=self.location
            while True:
                #look NE
                tempLoc=tempLoc.getNorthEast()#it dis
                if tempLoc==None:
                    break
                tempLoc=self.checkNextLocation(tempLoc)

                if tempLoc==None:
                    break
                else:
                    validMoves.append(tempLoc)
                    if self.virgin and self.secondSquare:
                        self.secondSquare=False
                        continue
                    break
                
                
            #look N for enemey pieces
            tempLoc=self.location.getNorth()
            enemyLoc=self.isEnemyPresent(tempLoc)

            if enemyLoc!=None:
                validMoves.append(enemyLoc)
                print("appended enemyLoc")

            #look E for enemey pieces
            tempLoc=self.location.getEast()
            enemyLoc=self.isEnemyPresent(tempLoc)

            if enemyLoc!=None:
                validMoves.append(enemyLoc)
                print("East emenyLoc appended")

                
        elif self.color=="black":
            #look SW
            tempLoc=self.location
            while True:
                #look NE
                tempLoc=tempLoc.getSouthWest()
                if tempLoc==None:
                    break
                tempLoc=self.checkNextLocation(tempLoc)
                if tempLoc==None:
                    break
                else:
                    validMoves.append(tempLoc)
                    if self.virgin and self.secondSquare:
                        self.secondSquare=False
                        continue
                    break

            #look S for enemey pieces
            tempLoc=self.location.getSouth()
            enemyLoc=self.isEnemyPresent(tempLoc)
            if enemyLoc!=None:
                validMoves.append(enemyLoc)

            #look W for enemey pieces
            tempLoc=self.location.getWest()
            enemyLoc=self.isEnemyPresent(tempLoc)
            if enemyLoc!=None:
                validMoves.append(enemyLoc)
                

        for move in validMoves:
            print (move.toString())
        return validMoves

    def toString(self):
        return "p "
