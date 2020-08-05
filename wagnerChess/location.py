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
    def __init__(self,letter,index,root):
        self.piece=None
        self.letter=letter
        self.index=index

        #connections holds other Location pointers
        self.connections={"n":None,
                          "ne":None,
                          "e":None,
                          "se":None,
                          "s":None,
                          "sw":None,
                          "w":None,
                          "nw":None}
        self.root=root

    def setPiece(self,piece):
        self.piece=piece

    def getPiece(self):
        return self.piece

    def toString(self):

        if self.piece==None:
            return self.letter+str(self.index)
        else:
            return self.piece.toString()
        
        
    def interconnect(self):
        #print("interconnect:",self.letter,self.index)
        if self.letter=="A":

            #A's dont have anything above
            del(self.connections["n"])
            del(self.connections["nw"])
            del(self.connections["w"])
            
            if self.index==7:#nothing right
                del(self.connections["ne"])
                del(self.connections["e"])
            elif self.index==0:#nothing left
                del(self.connections["sw"])
                del(self.connections["s"])
                
            #Make connections:
            if self.index==0:
                self.connections["e"]=self.root["board"].getBoard()["B,"+str(self.index+1)]
                self.connections["ne"]=self.root["board"].getBoard()["A,"+str(self.index+1)]
                self.connections["se"]=self.root["board"].getBoard()["B,"+str(self.index)]
                
            elif 0<self.index<7:
                self.connections["sw"]=self.root["board"].getBoard()["A,"+str(self.index-1)]
                self.connections["s"]=self.root["board"].getBoard()["B,"+str(self.index-1)]
                self.connections["se"]=self.root["board"].getBoard()["B,"+str(self.index)]
                self.connections["e"]=self.root["board"].getBoard()["B,"+str(self.index+1)]
                self.connections["ne"]=self.root["board"].getBoard()["A,"+str(self.index+1)]
                
            else:
                self.connections["sw"]=self.root["board"].getBoard()["A,"+str(self.index-1)]
                self.connections["s"]=self.root["board"].getBoard()["B,"+str(self.index-1)]
                self.connections["se"]=self.root["board"].getBoard()["B,"+str(self.index)]



        #you could totoally loop thgouth the apettrern in the iiddle
        elif self.letter!="H":


            prevL=self.__getPrevLetter(self.letter)
            nextL=self.__getNextLetter(self.letter)
            
            if self.index==7:#nothing right
                del(self.connections["n"])
                del(self.connections["ne"])
                del(self.connections["e"])
            elif self.index==0:#nothing left
                del(self.connections["w"])
                del(self.connections["sw"])
                del(self.connections["s"])
                
            #Make connections for middle of board:
            if self.index==0:
                self.connections["n"]=self.root["board"].getBoard()[prevL+","+str(self.index+1)]
                self.connections["nw"]=self.root["board"].getBoard()[prevL+","+str(self.index)]
                self.connections["se"]=self.root["board"].getBoard()[nextL+","+str(self.index)]
                self.connections["e"]=self.root["board"].getBoard()[nextL+","+str(self.index+1)]
                self.connections["ne"]=self.root["board"].getBoard()[self.letter+","+str(self.index+1)]
                
            elif 0<self.index<7:
                self.connections["n"]=self.root["board"].getBoard()[prevL+","+str(self.index+1)]
                self.connections["nw"]=self.root["board"].getBoard()[prevL+","+str(self.index)]
                self.connections["w"]=self.root["board"].getBoard()[prevL+","+str(self.index-1)]
                self.connections["sw"]=self.root["board"].getBoard()[self.letter+","+str(self.index-1)]
                self.connections["s"]=self.root["board"].getBoard()[nextL+","+str(self.index-1)]
                self.connections["se"]=self.root["board"].getBoard()[nextL+","+str(self.index)]
                self.connections["e"]=self.root["board"].getBoard()[nextL+","+str(self.index+1)]
                self.connections["ne"]=self.root["board"].getBoard()[self.letter+","+str(self.index+1)]
                
            else:
                self.connections["nw"]=self.root["board"].getBoard()[prevL+","+str(self.index)]
                self.connections["w"]=self.root["board"].getBoard()[prevL+","+str(self.index-1)]
                self.connections["sw"]=self.root["board"].getBoard()[self.letter+","+str(self.index-1)]
                self.connections["s"]=self.root["board"].getBoard()[nextL+","+str(self.index-1)]
                self.connections["se"]=self.root["board"].getBoard()[nextL+","+str(self.index)]
                
        elif self.letter=="H":

            del(self.connections["s"])
            del(self.connections["se"])
            del(self.connections["e"])

            if self.index==0:
                del(self.connections["sw"])
                del(self.connections["w"])
                
            elif self.index<7:
                del(self.connections["ne"])
                del(self.connections["n"])

            #make connections:
            if self.index==0:
                self.connections["nw"]=self.root["board"].getBoard()["G,"+str(self.index)]
                self.connections["n"]=self.root["board"].getBoard()["G,"+str(self.index+1)]
                self.connections["ne"]=self.root["board"].getBoard()["H,"+str(self.index+1)]
                
            elif 0<self.index<7:
                self.connections["sw"]=self.root["board"].getBoard()["H,"+str(self.index-1)]
                self.connections["w"]=self.root["board"].getBoard()["G,"+str(self.index-1)]
                self.connections["nw"]=self.root["board"].getBoard()["G,"+str(self.index)]
                self.connections["n"]=self.root["board"].getBoard()["G,"+str(self.index+1)]
                self.connections["ne"]=self.root["board"].getBoard()["H,"+str(self.index+1)]
                
            else:
                self.connections["nw"]=self.root["board"].getBoard()["G,"+str(self.index)]
                self.connections["w"]=self.root["board"].getBoard()["G,"+str(self.index-1)]
                self.connections["sw"]=self.root["board"].getBoard()["H,"+str(self.index-1)]




                
    def connect(self,connectionSiteNumber,locationPointer):
        self.connections[connectionSiteNumber]=locationPointer
        

    def get(self):
        return str(self.letter+str(self.index))


    def __getIndex(self,letter):
        letterList=Location.letterMap.keys()
        index=0
        for l in letterList:
            if letter==l:
                return index
            else:
                index+=1
            
    def __getPrevLetter(self,letter):
        letterList=list(Location.letterMap.keys())
        index=self.__getIndex(letter)
        
        if index==0:
            return Exception("nothing over here")
        return letterList[index-1]

    def __getNextLetter(self,letter):
        letterList=list(Location.letterMap.keys())
        index=self.__getIndex(letter)
        
        if index==7:
            return Exception("nothing over here")
        return letterList[index+1]
    
    def getNumber(self):
        return number

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
    
