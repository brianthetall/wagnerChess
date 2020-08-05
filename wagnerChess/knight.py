from piece import Piece

class Knight(Piece):

    def __init__(self,location,root,color):

        super(Knight,self).__init__(location,root,"knight",color)


    def listMoves(self):
        pass



    def toString(self):
        return "N "
