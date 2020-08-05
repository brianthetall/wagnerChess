from piece import Piece

class Pawn(Piece):

    def __init__(self,location,root,color):

        super(Pawn,self).__init__(location,root,"pawn",color)


    def listMoves(self):
        pass


    def toString(self):
        return "p "
