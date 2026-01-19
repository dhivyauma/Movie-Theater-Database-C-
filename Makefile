kCC = gcc
CFLAGS = -Wall -g

all: movieTheaterDB

movieTheaterDB: movieTheaterDB.o movieTheaterDB_actor.o movieTheaterDB_movie.o
	$(CC) $(CFLAGS) -o movieTheaterDB movieTheaterDB.o movieTheaterDB_actor.o movieTheaterDB_movie.o

movieTheaterDB.o: movieTheaterDB.c movieTheaterDB_actor.h movieTheaterDB_movie.h
	$(CC) $(CFLAGS) -c movieTheaterDB.c

movieTheaterDB_actor.o: movieTheaterDB_actor.c movieTheaterDB_actor.h
	$(CC) $(CFLAGS) -c movieTheaterDB_actor.c

movieTheaterDB_movie.o: movieTheaterDB_movie.c movieTheaterDB_movie.h
	$(CC) $(CFLAGS) -c movieTheaterDB_movie.c

clean:
	rm -f *.o movieTheaterDB

