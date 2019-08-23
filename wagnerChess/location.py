#when the Board is told to move a piece, it checks the logic of the request, THEN
#Updates the Piece-poiter inside the changing Locations.

class Location(object):


    letterMap={"A":[0,1,2,3,4,5,6,7],
               "B":[0,1,2,3,4,5,6,7],
               "C":[0,1,2,3,4,5,6,7],
               "D":[0,1,2,3,4,5,6,7],
               "E":[0,1,2,3,4,5,6,7],
               "F":[0,1,2,3,4,5,6,7],
               "G":[0,1,2,3,4,5,6,7],
               "H":[0,1,2,3,4,5,6,7]
    }

    #pass the Location something valid in the letterMap above
    def __init__(self,letter,index):
        self.piece=None
        self.letter=letter
        self.index=index
        self.connections={"0":None,"1":None,"2":None,"3":None,"4":None,"5":None,"6":None,"7":None}


    def interconnect(board):
        b=board.getBoard()
        if self.letter=="A":

            del(self.connections["1"])
            del(self.connections["2"])
            del(self.connections["3"])

            b["B,$d"%self.index].connect("2",self)
            b["B,$d"%(self.index+1)].connect("3",self)

            if self.index<7:
                b["A,$d"%self.index+1].connect("4",self)


        elif self.letter=="H":

            del(self.connections["5"])
            del(self.connections["6"])
            del(self.connections["7"])

            if self.index<7:
                b[].connect("",self)
                b[].connect("",self)
                b[].connect("",self)
            else:
                b[].connect("",self)
                b[].connect("",self)
                b[].connect("",self)

            if self.index>0:

                b[].connect("",self)
                b[].connect("",self)

                
            
            #this is going to get tedious, or you will find a pattern.

    def connect(self,connectionSiteNumber,locationPointer):
        self.connections[connectionSiteNumber]=locationPointer
        

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
        #raise Exception("not a Loation")

        xs,ys=location.get()
        if 
        '''
        pass
    
