#ifndef Text_H
#define Text_H
#include "header.h"
typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
} text;
void initText(text *t);
void freeText(text A);
void displayText(text t,SDL_Surface *screen);
#endif
