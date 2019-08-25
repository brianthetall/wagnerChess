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

            #A's dont have anything above
            del(self.connections["0"])
            del(self.connections["1"])
            del(self.connections["7"])
            
            if self.index==7:#nothing right
                del(self.connections["6"])
                del(self.connections["5"])
            elif self.index==0:#nothing left
                del(self.connections["2"])
                del(self.connections["3"])
                
            #Make connections:
            if self.index<7:
                b["B,$d"%self.index].connect("0",self)
                b["B,$d"%(self.index+1)].connect("1",self)
            else:
                b["A,$d"%self.index].connect("0",self)


        #you could totoally loop thgouth the apettrern in the iiddle
        elif self.letter!="H":


            prevLetter=self.__getPrevLetter(self.letter)
            nextLetter=self.__getNextLetter(self.letter)
            
            if self.index==7:#nothing right
                del(self.connections["7"])
                del(self.connections["6"])
                del(self.connections["5"])
            elif self.index==0:#nothing left
                del(self.connections["1"])
                del(self.connections["2"])
                del(self.connections["3"])
                
            #Make connections:
            if self.index==0:
                b["%s,$d"%(prevLetter,self.index)].connect("4",self)
                b["%s,$d"%(prevLetter,(self.index+1))].connect("3",self)

                b["%s,$d"%(nextLetter,self.index)].connect("0",self)
                b["%s,$d"%(nextLetter,(self.index+1))].connect("1",self)
                
            elif self.index<7:

                b["%s,$d"%(prevLetter,self.index)].connect("4",self)
                b["%s,$d"%(nextLetter,(self.index+1))].connect("3",self)
                b["%s,$d"%(nextLetter,(self.index-1))].connect("5",self)

                b["%s,$d"%(prevLetter,self.index)].connect("0",self)
                b["%s,$d"%(nextLetter,(self.index+1))].connect("1",self)
                b["%s,$d"%(nextLetter,(self.index-1))].connect("7",self)

            else:
                b["%s,$d"%(prevLetter,self.index)].connect("4",self)
                b["%s,$d"%(nextLetter,(self.index-1))].connect("3",self)
                
                b["%s,$d"%(prevLetter,self.index)].connect("0",self)
                b["%s,$d"%(nextLetter,(self.index-1))].connect("7",self)
                

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


    def __getIndex(self,letter):
        letterList=Location.letterMap.keys()
        index=0
        for l in letterList:
            if letter==l:
                return index
            else index++
            
    def __getPrevLetter(self,letter):
        letterList=Location.letterMap.keys()
        index=self.__getIndex(letter)
        if index==0:
            return Exception("nothing over here")
        return letterList[index-1]

    def __getNextLetter(self,letter):
        letterList=Location.letterMap.keys()
        index=self.__getIndex(letter)
        if index==7:
            return Exception("nothing over here")
        return letterList[index+1]
    
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
    
