from location import Location
from abc import ABCMeta, abstractmethod

class Piece(object):

    #location "B,3", for example
    #root: Player's root datastruct in RAM
    def __init__(self,location,root):

        self.root=root
        try:
            self.location=self.root["board"].getBoard()[location]
            
        except Exception as e:
            print ("error finding location inside of the board. Error=" , repr(e))
            raise


    @abstractmethod    
    def listMoves(self):
        #given current location, return list of legal locations
        #return Locations[]
        print ("this needs to be over written by subclass.")
