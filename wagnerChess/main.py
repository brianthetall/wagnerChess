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
    #port=input("Port: ")
    #port=26000
    #open a server-socket
    ssocket=socket.socket()
    ssocket.bind(("0.0.0.0",port))
    #print ("socket hostname:"+socket.gethostname())
    ssocket.listen()
    
else:#client
    #serverIp=input("Server IP:")
    serverIp="127.0.0.1"
    #port=input("Server Port:")
    #port=26000
    #open socket
    socket=socket.socket()

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
                c,addr=ssocket.accept()
                print("Sending to IP:"+str(addr))
                c.send(move.encode())
                c.close()
                
            else:
                #recv from Server player
                socket.connect((serverIp,port))
                move=socket.recv(1024).decode()
                print("Move from server: "+move)
                socket.close()
                
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
                socket.connect((serverIp,port))
                socket.send(move)
                socket.close()
                
            else:#Recv move from Client
                c,addr=ssocket.accept()
                print("Move from IP:"+(addr))
                move=c.recv()
                print("Move from client:"+move)
                c.close()
                
            b.movePiece(move,color="black")#execute update to board
            print(b.toString())
            break

        except NotYourPieceException as e:
            print(repr(e))
            continue
        
        except Exception as e:
            print (repr(e))
            time.sleep(1000)

        
