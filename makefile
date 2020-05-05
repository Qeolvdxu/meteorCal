FILE=source.c
CC=gcc
main: $(FILE) 
	$(CC) -o meteorSim $(FILE)
