from piece import Piece

class Queen(Piece):

    def __init__(self,location,color):

        super(Queen,self).__init__(location,color)

        if self.color=="black":
            self.location=Location("B",-1)
            
        elif self.color=="white":
            self.location=Location("N",-1)

    def listMoves(self):
        #how does this take into account the presence of other pieces
        #on the board?
        pass
