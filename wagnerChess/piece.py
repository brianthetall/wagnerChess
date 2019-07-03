from location import Location

class Piece(object):

    #root: Player's root datastruct in RAM
    def __init__(self,location,root):

        self.root=root
        self.location=location


    def listMoves(self):
        #given current location, return list of legal locations
        #return Locations[]
        print "this needs to be over written by subclass."
