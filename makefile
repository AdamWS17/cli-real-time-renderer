CC=gcc
CFLAGS=-I.

cliRenderer: cli_renderer.c
	$(CC) -o cliRenderer cli_renderer.c vector.c

clean:
	rm cliRenderer
