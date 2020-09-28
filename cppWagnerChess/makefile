CC=g++
CFLAGS= -lmariadb -I. -rpath='/usr/local/lib/gcc8/libstdc++.so.6'
#CFLAGS=-lncurses -lmariadb -I. -rpath='/usr/lib32'

chess:
	$(CC) -o chess *.cpp $(CFLAGS)
clean:
	rm -rf *.o chess
