class King(Piece):

    def __init__(self,location,root):

        super(King,self).__init__(location,root)

    def listMoves(self):
        #how does this take into account the presence of other pieces
        #on the board?
