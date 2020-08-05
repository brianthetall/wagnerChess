from board import Board


#main has board
#board has players && Locations
#players have pieces?

b=Board(args={})
b.linkLocations()
print(b.toString())

while True:
    move=input("White Move: ")#location,location
    #check for valid move
    print(move)
    try:
        b.movePiece(move,color="white")#execute update to board
    except Exception as e:
        print( repr(e))

        #create an NotYourPieceException
        #then re-ask for move!
        
    print(b.toString())

    move=input("Black Move: ")
    try:
        b.movePiece(move,color="black")#execute update to board
    except Exception as e:
        print (repr(e))

    print(b.toString())
