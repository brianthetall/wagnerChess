from piece import Piece
from termcolor import colored

class Pawn(Piece):

    def __init__(self,location,root,color):

        super(Pawn,self).__init__(location,root,"pawn",color)

        self.isPawn=True#used by checkNextLocation


    def listMoves(self):
        validMoves=[]
        self.secondSquare=True

        if self.color=="white":
            tempLoc=self.location
            while True:
                #look NE
                tempLoc=tempLoc.getNorthEast()
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
                

        #for move in validMoves:
        #    print ("Legal Move Pawn: " + move.toString())
        
        return validMoves

    def toString(self):
        if self.color=="white":
            return colored("\u0332p\u0332 |","white")
        else:
            return colored("\u0332p\u0332 |","red")
