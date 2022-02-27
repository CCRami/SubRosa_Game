Game: main.o menu.o options.o selectstart.o menuanimation.o
	gcc main.o menu.o options.o selectstart.o menuanimation.o -o Game -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o: main.c
	gcc -c main.c -g
menu.o: menu.c
	gcc -c menu.c -g
options.o: options.c
	gcc -c options.c -g
selectstart.o: selectstart.c
	gcc -c selectstart.c -g
menuanimation.o: menuanimation.c
	gcc -c menuanimation.c -g
