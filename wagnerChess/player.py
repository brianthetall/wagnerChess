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

            self.root['pieces'].append(King(location=board["H,1"],root=self.root,color=self.color))
            self.root['pieces'].append(Queen(location=board["G,0"],root=self.root,color=self.color))
            self.root['pieces'].append(Bishop(board["H,2"],root=self.root,color=self.color))
            self.root['pieces'].append(Bishop(board["F,0"],root=self.root,color=self.color))
            self.root['pieces'].append(Knight(board["H,3"],root=self.root,color=self.color))
            self.root['pieces'].append(Knight(board["E,0"],root=self.root,color=self.color))
            self.root['pieces'].append(Rook(board["H,4"],root=self.root,color=self.color))
            self.root['pieces'].append(Rook(board["D,0"],root=self.root,color=self.color))
            
            self.root['pieces'].append(Pawn(board["H,0"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["F,1"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["G,2"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["E,3"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["F,2"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["G,3"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["G,1"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["E,1"],root=self.root,color=self.color))
            
        else:
            self.root['pieces'].append(King(location=board["B,7"],root=self.root,color=self.color))
            self.root['pieces'].append(Queen(location=board["A,6"],root=self.root,color=self.color))
            self.root['pieces'].append(Bishop(board["A,5"],root=self.root,color=self.color))
            self.root['pieces'].append(Bishop(board["C,7"],root=self.root,color=self.color))
            self.root['pieces'].append(Knight(board["A,4"],root=self.root,color=self.color))
            self.root['pieces'].append(Knight(board["D,7"],root=self.root,color=self.color))
            self.root['pieces'].append(Rook(board["A,3"],root=self.root,color=self.color))
            self.root['pieces'].append(Rook(board["E,7"],root=self.root,color=self.color))
                                 
            self.root['pieces'].append(Pawn(board["A,7"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["C,6"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["B,5"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["B,4"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["C,5"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["D,4"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["B,6"],root=self.root,color=self.color))
            self.root['pieces'].append(Pawn(board["D,6"],root=self.root,color=self.color))
            

    #True/False, [] of pieces attacking opposing King
    def hasCheck(self):
        #collect all self.color pieces from the Collection
        checkingPieces=[]
        pieces=[]
        opposingKing=None

        for p in self.root['pieces']:
            print ("test:"+p.toString())
        
        for p in self.root['pieces']:
            if p.getColor()==self.color:
                pieces.append(p)
                print ("my piece:"+p.toString())
                
            elif p.getColor()!=self.color and p.getPieceType()=="king":
                opposingKing=p
                print ("opposing king: "+p.toString())


        print ("0")
        
        #see if each piece can attack the other King
        for p in pieces:
            print ("Can this threaten the king?"+p.toString()+"@"+p.getLocation().locString())
            threatenedPieces=p.canThreatenList()
            
            print("ThreatenedPieces=")
            for tp in threatenedPieces:
                print(tp.getLocation().toString()+'@'+tp.getLocation().locString())

            
            if opposingKing in threatenedPieces:
                print ("5")
                checkingPieces.append(p)

        print ("6")
        if len(checkingPieces)>0:
            return True,checkingPieces
        else:
            return False,checkingPieces
