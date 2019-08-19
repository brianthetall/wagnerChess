#when the Board is told to move a piece, it checks the logic of the request, THEN
#Updates the Piece-poiter inside the changing Locations.

class Location(object):


    letterMap={"A":[0,1,2,3,4,5,6,7],
               "B":[0,1,2,3,4,5,6],
               "C":[0,1,2,3,4,5],
               "D":[0,1,2,3,4],
               "E":[0,1,2,3],
               "F":[0,1,2],
               "G":[0,1],
               "H":[0]
    }
                    
    def __init__(self,x,y):

        #this is probably useful for equals()
                
        try:
            if x not in range(0,7) or y not in range(0,7):
                raise Exception("invalid x or y range: %d,%d" % (x,y))
            self.x=x
            self.y=y

        except Exception:
            print "Did you send an int? Type=%s,%s"%(type(x),type(y))
            raise
        
        self.piece=None


    def get(self):
        return self.x,self.y


    def getNumber(self):
        return number

    def placePiece(self,piece):
        self.piece=piece

    def clearPiece(self):
        self.piece=None

    def equals(self,location):
        '''
        if not isinstance(location,Location):
            raise Exception("not a Loation")

        xs,ys=location.get()
        if 
        '''
        pass
    
