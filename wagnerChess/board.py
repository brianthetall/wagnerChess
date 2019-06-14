from location import Location

class Board(object):

    def __init__(self):

        self.board=[]
        
        #update Location to track a Piece pointer!

        letters=Location.letterMap.keys()
        for l in letters:
            numbers=Location.letterMap[l]
            for n in numbers:
                self.board.append( Location(l,n) )                
