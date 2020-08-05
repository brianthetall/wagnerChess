from board import Board


#main has board
#board has players && Locations
#players have pieces?

b=Board(args={})
b.linkLocations()
print b.toString()
