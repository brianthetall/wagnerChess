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

            self.root['pieces']=[King(location=board["H,1"],root=self.root,color=self.color),
                                 Queen(location=board["G,0"],root=self.root,color=self.color),
                                 Bishop(board["H,2"],root=self.root,color=self.color),
                                 Bishop(board["F,0"],root=self.root,color=self.color),
                                 Knight(board["H,3"],root=self.root,color=self.color),
                                 Knight(board["E,0"],root=self.root,color=self.color),
                                 Rook(board["H,4"],root=self.root,color=self.color),
                                 Rook(board["D,0"],root=self.root,color=self.color),
                                 
                                 Pawn(board["H,0"],root=self.root,color=self.color),
                                 Pawn(board["F,1"],root=self.root,color=self.color),
                                 Pawn(board["G,2"],root=self.root,color=self.color),
                                 Pawn(board["E,3"],root=self.root,color=self.color),
                                 Pawn(board["F,2"],root=self.root,color=self.color),
                                 Pawn(board["G,3"],root=self.root,color=self.color),
                                 Pawn(board["G,1"],root=self.root,color=self.color),
                                 Pawn(board["E,1"],root=self.root,color=self.color)
            ]
        else:
            self.root['pieces']=[King(location=board["B,7"],root=self.root,color=self.color),
                                 Queen(location=board["A,6"],root=self.root,color=self.color),
                                 Bishop(board["A,5"],root=self.root,color=self.color),
                                 Bishop(board["C,7"],root=self.root,color=self.color),
                                 Knight(board["A,4"],root=self.root,color=self.color),
                                 Knight(board["D,7"],root=self.root,color=self.color),
                                 Rook(board["A,3"],root=self.root,color=self.color),
                                 Rook(board["E,7"],root=self.root,color=self.color),
                                 
                                 Pawn(board["A,7"],root=self.root,color=self.color),
                                 Pawn(board["C,6"],root=self.root,color=self.color),
                                 Pawn(board["B,5"],root=self.root,color=self.color),
                                 Pawn(board["B,4"],root=self.root,color=self.color),
                                 Pawn(board["C,5"],root=self.root,color=self.color),
                                 Pawn(board["D,4"],root=self.root,color=self.color),
                                 Pawn(board["B,6"],root=self.root,color=self.color),
                                 Pawn(board["D,6"],root=self.root,color=self.color)
            ]

    #True/False, [] of pieces attacking opposing King
    def hasCheck(self):
        #collect all self.color pieces from the Collection
        checkingPieces=[]
        pieces=[]
        opposingKing=None

        for p in self.root['pieces']:
            if p.getColor()==self.color:
                pieces.append(p)
                print (p.toString())
                
            elif p.getColor()!=self.color and p.getPieceType()=="king":
                opposingKing=p
                print (p.toString())


        print ("0")
        
        #see if each piece can attack the other King
        for p in pieces:
            print ("Can this threaten the king?"+p.toString())
            threatenedPieces=p.canThreatenList()
            
            print("ThreatenedPieces=")
            print(threatenedPieces)
            if opposingKing in threatenedPieces:
                print ("5")
                checkingPieces.append(p)

        print ("6")
        if len(checkingPieces)>0:
            return True,checkingPieces
        else:
            return False,checkingPieces
