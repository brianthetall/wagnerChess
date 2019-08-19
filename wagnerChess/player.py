from piece import Piece
from king import King
from queen import Queen
from bishop import Bishop
from knight import Knight
from rook import Rook
from pawn import Pawn

class Player(object):

    def __init__(self,color):

        if color not in ["white","black"]:
            raise Exception("invalid color")
        self.color=color

        
        self.root={
            "player":self,
            "board":None,
            "pieces":[]
            
        self.root['board']=Board(self.root)
        #but where and how are the piece pointers kept?
        #passing a datastruct full of everything
        #regardless of color, THIS player, lives on the LOW end
        #The larger the index number gets, the deeper into enemy territory
        if color=="black":

            self.pieces=[ King(
            
            
            self.root['pieces']=[King(location=Location("B",1),root=self.root),
                                 Queen(location=Location("B",-1),root=self.root),
                                 Bishop(Location("C",-1),root=self.root),
                                 Bishop(Location("C",1),root=self.root),
                                 Knight(Location("D",-2),root=self.root),
                                 Knight(Location("D",2),root=self.root),
                                 Rook(Location("E",-2),root=self.root),
                                 Rook(Location("E",2),root=self.root),
                                 
                                 Pawn(Location("A",0),root=self.root),
                                 Pawn(Location("C",0),root=self.root),
                                 Pawn(Location("E",0),root=self.root),
                                 Pawn(Location("G",0),root=self.root),
                                 Pawn(Location("E",-1),root=self.root),
                                 Pawn(Location("D",-1),root=self.root),
                                 Pawn(Location("E",1),root=self.root),
                                 Pawn(Location("D",1),root=self.root)
            ]
                
        elif color=="white":
            self.root['pieces']=[King(location=Location("N",1),root=self.root),
                                 Queen(location=Location("N",-1),root=self.root),
                                 Bishop(Location("M",-1),root=self.root),
                                 Bishop(Location("M",1),root=self.root),
                                 Knight(Location("L",-2),root=self.root),
                                 Knight(Location("L",2),root=self.root),
                                 Rook(Location("K",-2),root=self.root),
                                 Rook(Location("K",2),root=self.root),

                                 Pawn(Location("O",0),root=self.root),
                                 Pawn(Location("M",0),root=self.root),
                                 Pawn(Location("K",0),root=self.root),
                                 Pawn(Location("I",0),root=self.root),
                                 Pawn(Location("L",-1),root=self.root),
                                 Pawn(Location("K",-1),root=self.root),
                                 Pawn(Location("L",1),root=self.root),
                                 Pawn(Location("K",1),root=self.root)
                    ]

    def killPiece(self):
        #remove This from self.pieces
        pass

    def move(self):
        pass

