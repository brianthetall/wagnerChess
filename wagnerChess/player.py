from piece import Piece
from king import King
from queen import Queen
from bishop import Bishop
from knight import Knight
from rook import Rook
from pawn import Pawn

class Player(object):

    def __init__(self,color,boardRoot):

        if color not in ["white","black"]:
            raise Exception("invalid color")
        self.color=color

        self.root=boardRoot

        board=self.root["board"].getBoard()#board[","]

        if self.color=='white':

            self.root['pieces']=[King(location=board["A,1"],root=self.root),
                                 Queen(location=board["B,0"],root=self.root),
                                 Bishop(board["C,0"],root=self.root),
                                 Bishop(board["A,2"],root=self.root),
                                 Knight(board["D,0"],root=self.root),
                                 Knight(board["A,3"],root=self.root),
                                 Rook(board["E,0"],root=self.root),
                                 Rook(board["A,4"],root=self.root),
                                 
                                 Pawn(board["A,0"],root=self.root),
                                 Pawn(board["B,1"],root=self.root),
                                 Pawn(board["C,2"],root=self.root),
                                 Pawn(board["D,3"],root=self.root),
                                 Pawn(board["E,4"],root=self.root),
                                 Pawn(board["F,5"],root=self.root),
                                 Pawn(board["G,6"],root=self.root),
                                 Pawn(board["H,7"],root=self.root)
            ]
        else:
            self.root['pieces']=[King(location=board["B,0"],root=self.root),
                                 Queen(location=board["A,1"],root=self.root),
                                 Bishop(board["C,0"],root=self.root),
                                 Bishop(board["A,2"],root=self.root),
                                 Knight(board["D,0"],root=self.root),
                                 Knight(board["A,3"],root=self.root),
                                 Rook(board["E,0"],root=self.root),
                                 Rook(board["A,4"],root=self.root),
                                 
                                 Pawn(board["A,0"],root=self.root),
                                 Pawn(board["B,1"],root=self.root),
                                 Pawn(board["C,2"],root=self.root),
                                 Pawn(board["D,3"],root=self.root),
                                 Pawn(board["E,4"],root=self.root),
                                 Pawn(board["F,5"],root=self.root),
                                 Pawn(board["G,6"],root=self.root),
                                 Pawn(board["H,7"],root=self.root)
            ]
    def killPiece(self):
        #remove This from self.pieces
        pass

    def move(self):
        pass

