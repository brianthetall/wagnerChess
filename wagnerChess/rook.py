from piece import Piece

class Rook(Piece):

    def __init__(self,location,root,color):

        super(Rook,self).__init__(location,root,"rook",color)


    #return a list of valid Locations
    def listMoves(self):
        return []



    def toString(self):
        return "R "
