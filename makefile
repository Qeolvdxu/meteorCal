FILE=source.c
CC=gcc
main: $(FILE) 
	$(CC) -o meteorCal $(FILE) -lm
