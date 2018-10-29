class Board(object):

    def __init__(self):

        self.players=[Player("white"),Player("black")]

        #update Location to track a Piece pointer!
        self.board=[
            Location("A",0),
            Location("B",-1),
            Location("B",1),
            Location("C",-1),
            Location("C",0),
            Location("C",1),
            Location("D",-2),
            Location("D",-1),
            Location("D",1),
            Location("D",2),
            Location("E",-2),
            Location("E",-1),
            Location("E",0),
            Location("E",1),
            Location("E",2),            
            Location("F",-3),
            Location("F",-2),
            Location("F",-1),
            Location("F",1),
            Location("F",2),
            Location("F",3),
            Location("G",-3),
            Location("G",-2),
            Location("G",-1),
            Location("G",0),
            Location("G",1),
            Location("G",2),
            Location("G",3),
            Location("H",-4),
            Location("H",-3),
            Location("H",-2),
            Location("H",-1),
            Location("H",0),
            Location("H",1),
            Location("H",2),
            Location("H",3),
            Location("H",4),

            Location("O",0),
            Location("N",-1),
            Location("N",1),
            Location("M",-1),
            Location("M",0),
            Location("M",1),
            Location("L",-2),
            Location("L",-1),
            Location("L",1),
            Location("L",2),
            Location("K",-2),
            Location("K",-1),
            Location("K",0),
            Location("K",1),
            Location("K",2),
            
            Location("J",-3),
            Location("J",-2),
            Location("J",-1),
            Location("J",1),
            Location("J",2),
            Location("J",3),
            Location("I",-3),
            Location("I",-2),
            Location("I",-1),
            Location("I",0),
            Location("I",1),
            Location("I",2),
            Location("I",3)
        ]


b=Board()
while(1):
    result=b.tick()
    if result in ["checkmate","stalemate"]:
        break#the game is over
