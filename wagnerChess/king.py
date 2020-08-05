from piece import Piece

class King(Piece):

    def __init__(self,location,root,color):

        super(King,self).__init__(location,root,"king",color)
        pass

    def listMoves(self):
        #how does this take into account the presence of other pieces
        #on the board?
        pass


    def toString(self):
        return "K "
