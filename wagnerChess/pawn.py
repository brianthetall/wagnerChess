from piece import Piece

class Pawn(Piece):

    def __init__(self,location,root):

        super(Pawn,self).__init__(location,root,"pawn")


    def listMoves(self):
        pass