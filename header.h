#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include "stdbool.h"
#define SCREEN_W 1920
#define SCREEN_H 1080
typedef struct{
	SDL_Rect pos;
	SDL_Surface *img;
}image;

typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
}text;
void initText(text *A,text *B,text *C,text *D);
void freeText(text A,text B,text C, text D);
void displayText(text t,SDL_Surface *screen);
void initButtons(image *A,image *B, image *C,image *D,image *E, image *F);
void initBackground(image *Backg);
void afficher(image A,SDL_Surface *screen);
void libererButtons(image A,image B, image C,image E,image F,image G);
void afficherparposition(int position, image *A,image *B, image *C,image *D);
void closeEverything();

void initSettingsButtons(image *A,image *B, image *C,image *D,image *E,Mix_Chunk *chunk);
int paintOptionsScreen(SDL_Surface* screen,SDL_Event *event,Mix_Chunk *chunk,int *volume);

void initTextagent(text *A,text *B);
void freeTextagent(text A,text B);
void displayTextagent(text t,SDL_Surface *screen);
void afficherparpositionagent(int position, image *A,image *B, image *C,image *D,image *E,image *F);
void initSettingsButtonsagent(image *A,image *B, image *C,image *D,image *E,image *F);
int paintOptionsScreenagent (SDL_Surface *screen,SDL_Event *event2,Mix_Chunk *chunk);
void afficherparpositionsettings(int position, image *A,image *B);

void initanimation(image tabimg[]);
void libereranimation (image tabimg[]);
