from board import Board
from notYourPieceException import NotYourPieceException
import socket
import time

while True:
    mode=input("(S)erver or (C)lient?")
    if mode=="S" or mode=="s" or mode=="C" or mode=="c":
        break
    print ("Try again!")


port=26000
if mode=="s" or mode=="S":#server
    #open a server-socket
    ssocket=socket.socket()
    ssocket.bind(("0.0.0.0",port))
    ssocket.listen()
    c,addr=ssocket.accept()
    
else:#client
    serverIp=input("Server IP:")
    #serverIp="127.0.0.1"
    #open socket
    socket=socket.socket()
    socket.connect((serverIp,port))

#main has board
#board has players && Locations
#players have pieces?

b=Board(args={})
b.linkLocations()
print(b.toString())

while True:

    while True:
        try:
            if mode=="s" or mode=="S":
                move=input("White Move: ")#location,location
                #send move to the Client
                print("Sending to IP:"+str(addr))
                c.send(move.encode())
                
            else:
                #recv from Server player
                move=socket.recv(1024).decode()
                print("Move from server: "+move)
                
            #check for valid move
            b.movePiece(move,color="white")#execute update to board
            print(b.toString())
            break

        except NotYourPieceException as e:
            print(repr(e))
            continue
        
        except Exception as e:
            print( repr(e))
            time.sleep(1000)
        

    while True:
        try:
            if mode=="c" or mode=="C":
                move=input("Black Move: ")
                #send move to the Server
                socket.send(move.encode())
                
            else:#Recv move from Client
                print("Move from Black-IP:"+str(addr))
                move=c.recv(10).decode()
                print("Move from client:"+move)
                
            b.movePiece(move,color="black")#execute update to board
            print(b.toString())
            break

        except NotYourPieceException as e:
            print(repr(e))
            continue
        
        except Exception as e:
            print (repr(e))
            time.sleep(1000)
