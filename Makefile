CC=wpi
CFLAGS=-I .




main:main.o
    $(CC) main.o -o main $(CFLAGS)

main.o:main.s
    $(CC) -c main.s -o main.o $(CFLAGS)

main.s:main.i
    $(CC) -S main.i -o main.s $(CFLAG)

main.i:main.c gpio-wpi.h
   $(CC) -E main.c -o main.i $(CFLAGS)
