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
        self.connections={"n":None,"ne":None,"e":None,"se":None,"s":None,"sw":None,"w":None,"nw":None}
        self.root=root



    def toString(self):

        if empty:
            print "_"
        else:
            #print the piece.toString()
            
        """
        print(self.letter+str(self.index))
        for c in list(self.connections.keys()):
            if not self.connections[c]==None:
                print(self.connections[c].get())
        """

        
    def interconnect(self):
        print("interconnect:",self.letter,self.index)
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
                print (prevLetter,",",self.index,sep='')
                s=prevLetter+","+str(self.index)
                print(s)
                
                b[prevLetter+","+str(self.index)].connect("4",self)
                b[prevLetter+","+str(self.index+1)].connect("3",self)

                b[nextLetter+","+str(self.index)].connect("0",self)
                b[nextLetter+","+str(self.index+1)].connect("1",self)
                
            elif self.index<7:

                b[prevLetter+","+str(self.index)].connect("4",self)
                b[nextLetter+","+str(self.index+1)].connect("3",self)
                b[nextLetter+","+str(self.index-1)].connect("5",self)

                b[prevLetter+","+str(self.index)].connect("0",self)
                b[nextLetter+","+str(self.index+1)].connect("1",self)
                b[nextLetter+","+str(self.index-1)].connect("7",self)

            else:
                b[prevLetter+","+str(self.index)].connect("4",self)
                b[nextLetter+","+str(self.index-1)].connect("3",self)
                
                b[prevLetter+","+str(self.index)].connect("0",self)
                b[nextLetter+","+str(self.index-1)].connect("7",self)
                

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
            #you are here
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



        print("Connections:",self.connections)
        print(self.toString())



                
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
    
