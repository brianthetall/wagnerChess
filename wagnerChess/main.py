from board import Board


#main has board
#board has players && Locations
#players have pieces?

b=Board(args={})
b.linkLocations()
print b.toString()

while True:
    move=raw_input("White Move: ")#location,location
    #check for valid move
    print move
    b.movePiece(move)#execute update to board
    print b.toString()

    move=raw_input("Black Move: ")
    b.movePiece(move)#execute update to board
    print b.toString()
