from inCheckException import InCheckException
from notYourPieceException import NotYourPieceException
from illegalMoveException import IllegalMoveException

from player import Player
from piece import Piece
from location import Location
#make the litter of Locations; they will know their UID on init
#Later we call a connect the Links function to interlink the Location Objects.

class Board(object):

    def __init__(self,args={}):

        self.board={}#holds the locations; use getBoard(), not root pointer
        self.root={"players":{"white":None,"black":None},
                   "board":self,
                   "pieces":[]}
        
        #update Location to track a Piece pointer!

        letters=Location.letterMap.keys()
        for l in letters:
            numbers=Location.letterMap[l]
            for n in numbers:
                index="%s,%d" % (l,n)
                self.board[index] = Location(l,n,self.root)


        #the players can reference the Locations made above!
        self.root["players"]["white"]=Player("white",self.root)
        self.root["players"]["black"]=Player("black",self.root)

        
    #return None, or Color in check & opposing pieces holding the check
    def lookForCheck(self,color):
        print ("lookForCheck")

        if color=="white":
            hasCheck, pieces = self.root["players"]["black"].hasCheck()
        else:
            hasCheck, pieces = self.root["players"]["white"].hasCheck()
            
        if hasCheck==True:
            print("check found")
            print(pieces)
        else:
            print("no check found")
            
        if hasCheck and color=="white":
            return "white", pieces
        elif hasCheck and color=="black":
            return "black", pieces
    
        return None,None
            
        

    #make something nice to see on the console
    def toString(self):
        #b=self.getBoard()

        retval=""
        #print locations and pieces
        for loc in Location.letterMap:
            for i in range(0,len(Location.letterMap["A"])):
                retval+="\u0332 "+self.board[loc+","+str(i)].toString()
                if i==7:
                    retval+="\n"


        retval+="\n"
        #print just the locations
        for loc in Location.letterMap:
            for i in range(0,len(Location.letterMap["A"])):
                retval+="\u0332 \u0332"+loc+"\u0332"+str(i)+"\u0332|"
                if i==7:
                    retval+="\n"

                    
        return retval

    def movePiece(self,move,color):#move is in form: "E1,D0"
        strings=move.split(",")
        currentLocString=strings[0]
        newLocString=strings[1]
        replacedPieceTemp=None
        
        #put a comma in the String, then pull the Loc from self.board
        currentLoc=self.board[currentLocString[0]+","+currentLocString[1]]
        newLoc=self.board[newLocString[0]+","+newLocString[1]]
        print( "Piece: "+currentLoc.toString())
        print( "New Location: "+newLoc.toString())

        #is there a piece @ currentLoc?
        piece=currentLoc.getPiece()
        if piece==None:
            raise Exception("No piece at that location!")
        elif piece.getColor() != color:
            raise NotYourPieceException()
        else:
            validLocations=piece.listMoves()#check if move is legal
            if newLoc not in validLocations:
                raise IllegalMoveException()

            replacedPieceTemp=newLoc.getPiece()#hold in case this results in us being in check
            piece.changeLocation(newLoc)
            currentLoc.setPiece(None)
            firstTime=piece.sex()#revoke virginity

            #check for check?
            colorInCheck,pieceList=self.lookForCheck(piece.getColor())
            if colorInCheck==piece.getColor():

                #UNDO the move on the board
                if firstTime==True:
                    piece.unsex()
                piece.changeLocation(currentLoc)

                if replacedPieceTemp!=None:
                    replacedPieceTemp.changeLocation(newLoc)
                else:
                    newLoc.setPiece(None)
                    
                raise InCheckException(colorInCheck+" is in check!")
    
        
    def linkLocations(self):
        #The locations are linked together to form the board
        #8-way max, links from a given piece
        #min of 2 links
        for loc in self.board:
            self.board[loc].interconnect()

            
    def getBoard(self):
        return self.board
