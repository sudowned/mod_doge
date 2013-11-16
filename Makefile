CC=apxs2
CFLAGS= -ldoge

default: mod_doge

mod_doge:
	$(CC) -c mod_doge.c $(CFLAGS)

install:
	$(CC) -i -a -c mod_doge.c $(CFLAGS)

