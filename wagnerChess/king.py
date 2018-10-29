class King(Piece):

    def __init__(self,location,color):

        super(King,self).__init__(location,color)

    def listMoves(self):
        #how does this take into account the presence of other pieces
        #on the board?
