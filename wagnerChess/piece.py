from location import Location

class Piece(object):

    def __init__(self,location,color):

        self.location=location
        if color not in ["white","black"]:
            raise Exception("invalid color")
        
        self.color=color


    def listMoves(self):
        #given current location, return list of legal locations
        #return Locations[]
        print "this needs to be over written by subclass."
