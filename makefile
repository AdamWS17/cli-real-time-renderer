CC=gcc
CFLAGS=-I.

cliRenderer: cli_renderer.c
	$(CC) -o cliRenderer cli_renderer.c

clean:
	rm cliRenderer
