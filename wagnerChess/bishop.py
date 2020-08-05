from piece import Piece

class Bishop(Piece):
    
    def __init__(self,location,root,color):

        super(Bishop,self).__init__(location,root,"bishop",color)


        
    def listMoves(self):
        pass


    def toString(self):
        return "B "
