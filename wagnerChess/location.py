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
        self.connections={"0":None,"1":None,"2":None,"3":None,"4":None,"5":None,"6":None,"7":None}
        self.root=root



    def toString(self):
        print(self.letter+str(self.index))
        for c in list(self.connections.keys()):
            if not self.connections[c]==None:
                print(self.connections[c].get())

    def interconnect(self):
        print("interconnect:",self.letter,self.index)
        b=self.root["board"].getBoard()
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
                b["B,"+str(self.index)].connect("0",self)
                b["B,"+str(self.index+1)].connect("1",self)
            else:
                b["A,"+str(self.index)].connect("0",self)


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

            del(self.connections["5"])
            del(self.connections["6"])
            del(self.connections["7"])

            if self.index==0:
                b["G,0"].connect("4",self)
                b["G,1"].connect("3",self)

            elif self.index<7:
                b["G,%d"%(self.index-1)].connect("5",self)
                b["G,%d"%(self.index)].connect("4",self)
                b["G,%d"%(self.index+1)].connect("3",self)

            else:
                b["G,7"].connect("4",self)
                b["G,6"].connect("5",self)

        #
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
    
