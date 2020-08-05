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
    try:
        b.movePiece(move)#execute update to board
    except Exception as e:
        print repr(e)
        
    print b.toString()

    move=raw_input("Black Move: ")
    try:
        b.movePiece(move)#execute update to board
    except Exception as e:
        print repr(e)

    print b.toString()
