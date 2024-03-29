Game: main.o menu.o options.o selectstart.o menuanimation.o perso.o minimap.o score.o entity.o ennemie.o enigmetf.o enigmeif.o background.o collision.o tictac.o sauv.o
	gcc main.o menu.o options.o selectstart.o menuanimation.o perso.o minimap.o score.o entity.o ennemie.o enigmetf.o enigmeif.o background.o collision.o tictac.o sauv.o -o Game -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
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
perso.o: perso.c
	gcc -c perso.c -g
minimap.o: minimap.c
	gcc -c minimap.c -g
score.o: score.c
	gcc -c score.c -g
entity.o:entity.c
	gcc -c entity.c -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -g
enigmetf.o:enigmetf.c
	gcc -c enigmetf.c
enigmeif.o :enigmeif.c
	gcc -c enigmeif.c -g
background.o: background.c
	gcc -c background.c -g
collision.o: collision.c
	gcc -c collision.c -g
tictac.o: tictac.c
	gcc -c tictac.c -g
sauv.o: sauv.c
	gcc -c sauv.c -g
