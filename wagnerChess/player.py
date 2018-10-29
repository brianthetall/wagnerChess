from piece import Piece
from king import King

class Player(object):

    def __init__(self,color):

        if color not in ["white","black"]:
            raise Exception("invalid color")
        self.color=color
        
        if color=="black":
            self.pieces=[King(location=Location("B",1),color=self.color),
                         Queen(location=Location("B",-1),color=self.color),
                         Bishop(Location("C",-1),color=self.color),
                         Bishop(Location("C",1),color=self.color),
                         Knight(Location("D",-2),color=self.color),
                         Knight(Location("D",2),color=self.color),
                         Rook(Location("E",-2),color=self.color),
                         Rook(Location("E",2),color=self.color),

                         Pawn(Location("A",0),color=self.color),
                         Pawn(Location("C",0),color=self.color),
                         Pawn(Location("E",0),color=self.color),
                         Pawn(Location("G",0),color=self.color),
                         Pawn(Location("E",-1),color=self.color),
                         Pawn(Location("D",-1),color=self.color),
                         Pawn(Location("E",1),color=self.color),
                         Pawn(Location("D",1),color=self.color)
            ]

        elif color=="white":
            self.pieces=[King(location=Location("N",1),color=self.color),
                         Queen(location=Location("N",-1),color=self.color),
                         Bishop(Location("M",-1),color=self.color),
                         Bishop(Location("M",1),color=self.color),
                         Knight(Location("L",-2),color=self.color),
                         Knight(Location("L",2),color=self.color),
                         Rook(Location("K",-2),color=self.color),
                         Rook(Location("K",2),color=self.color),

                         Pawn(Location("O",0),color=self.color),
                         Pawn(Location("M",0),color=self.color),
                         Pawn(Location("K",0),color=self.color),
                         Pawn(Location("I",0),color=self.color),
                         Pawn(Location("L",-1),color=self.color),
                         Pawn(Location("K",-1),color=self.color),
                         Pawn(Location("L",1),color=self.color),
                         Pawn(Location("K",1),color=self.color)
            ]

    def killPiece(self):
        #remove This from self.pieces
        
            
    def move(self):
