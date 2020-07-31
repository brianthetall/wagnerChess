from piece import Piece

class Queen(Piece):

    def __init__(self,location,root):

        super(Queen,self).__init__(location,root,"queen")

    def listMoves(self):
        #how does this take into account the presence of other pieces
        #on the board?
        pass

    def toString(self):
        return "Q"
