prog: main.o menu.o
	gcc main.o menu.o -o prog -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image -g
menu.o:menu.c
	gcc -c menu.c -g
main.o:main.c
	gcc -c main.c -g

