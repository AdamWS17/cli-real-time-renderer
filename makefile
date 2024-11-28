CC=gcc
CFLAGS=-I.

cliRenderer: cli_renderer.c
	$(CC) -o cliRenderer cli_renderer.c vector.c matrix.c

clean:
	rm cliRenderer
