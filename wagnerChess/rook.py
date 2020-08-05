from piece import Piece

class Rook(Piece):

    def __init__(self,location,root,color):

        super(Rook,self).__init__(location,root,"rook",color)


    def listMoves(self):
        pass



    def toString(self):
        return "R "
