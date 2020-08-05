from piece import Piece
from king import King
from queen import Queen
from bishop import Bishop
from knight import Knight
from rook import Rook
from pawn import Pawn

class Player(object):

    def __init__(self,color,boardRoot):


        print("init Player",color)
        
        if color not in ["white","black"]:
            raise Exception("invalid color")
        self.color=color

        self.root=boardRoot

        board=self.root["board"].getBoard()#board[","]

        if self.color=='white':

            self.root['pieces']=[King(location=board["H,1"],root=self.root),
                                 Queen(location=board["F,0"],root=self.root),
                                 Bishop(board["H,2"],root=self.root),
                                 Bishop(board["G,0"],root=self.root),
                                 Knight(board["H,3"],root=self.root),
                                 Knight(board["D,0"],root=self.root),
                                 Rook(board["H,4"],root=self.root),
                                 Rook(board["E,0"],root=self.root),
                                 
                                 Pawn(board["H,0"],root=self.root),
                                 Pawn(board["F,1"],root=self.root),
                                 Pawn(board["G,2"],root=self.root),
                                 Pawn(board["D,3"],root=self.root),
                                 Pawn(board["F,2"],root=self.root),
                                 Pawn(board["F,3"],root=self.root),
                                 Pawn(board["G,1"],root=self.root),
                                 Pawn(board["D,1"],root=self.root)
            ]
        else:
            self.root['pieces']=[King(location=board["C,7"],root=self.root),
                                 Queen(location=board["A,6"],root=self.root),
                                 Bishop(board["A,5"],root=self.root),
                                 Bishop(board["B,7"],root=self.root),
                                 Knight(board["A,4"],root=self.root),
                                 Knight(board["E,7"],root=self.root),
                                 Rook(board["A,3"],root=self.root),
                                 Rook(board["D,7"],root=self.root),
                                 
                                 Pawn(board["A,7"],root=self.root),
                                 Pawn(board["C,6"],root=self.root),
                                 Pawn(board["B,5"],root=self.root),
                                 Pawn(board["E,4"],root=self.root),
                                 Pawn(board["C,5"],root=self.root),
                                 Pawn(board["C,4"],root=self.root),
                                 Pawn(board["B,6"],root=self.root),
                                 Pawn(board["E,6"],root=self.root)
            ]
    def killPiece(self):
        #remove This from self.pieces
        pass

    def move(self):
        pass

