from location import Location
from abc import ABCMeta, abstractmethod

class Piece(object):

    #location "B,3", for example
    #root: Player's root datastruct in RAM
    def __init__(self,location,root):

        self.root=root
        self.location=location


    @abstractmethod    
    def listMoves(self):
        #given current location, return list of legal locations
        #return Locations[]
        print ("this needs to be over written by subclass.")
