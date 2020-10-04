CC=g++
CFLAGS= -lmariadb -I. -I/usr/local/include
PIECES=piece.cpp king.cpp queen.cpp bishop.cpp knight.cpp rook.cpp pawn.cpp

chess:
	$(CC) -o chess.cgi main.cpp ezSql.cpp board.cpp location.cpp  coordinate.cpp player.cpp $(PIECES)  $(CFLAGS)
	$(CC) -o newgame.cgi newGame.cpp ezSql.cpp  $(CFLAGS)

	sudo cp chess.cgi newgame.cgi $(CGI)/

clean:
	rm -rf *.o chess.cgi newgame.cgi
