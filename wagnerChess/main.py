from board import Board
from notYourPieceException import NotYourPieceException

#main has board
#board has players && Locations
#players have pieces?

b=Board(args={})
b.linkLocations()
print(b.toString())

while True:

    while True:
        try:
            move=input("White Move: ")#location,location
            #check for valid move
            b.movePiece(move,color="white")#execute update to board
            print(b.toString())
            break

        except NotYourPieceException as e:
            print(repr(e))
            continue
        
        except Exception as e:
            print( repr(e))
                        
        

    while True:
        try:
            move=input("Black Move: ")
            b.movePiece(move,color="black")#execute update to board
            print(b.toString())
            break

        except NotYourPieceException as e:
            print(repr(e))
            continue
        
        except Exception as e:
            print (repr(e))

        
