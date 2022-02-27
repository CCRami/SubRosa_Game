#include "header.h"

void initButtons(image *A,image *B, image *C,image *D,image *E, image *F)
{
	A->img = IMG_Load("1x/Startselected.png");
		if (A->img== NULL) {
			return ;
		}
	A->pos.x = 270;
	A->pos.y = 300;
	
	B->img = IMG_Load("1x/Settingsunselected.png");
		if (B->img== NULL) {
			return ;
		}
	B->pos.x = 270;
	B->pos.y = 500;

	C->img = IMG_Load("1x/Quitunselected.png");
		if (C->img== NULL) {
			return ;
		}
	C->pos.x = 320;
	C->pos.y = 900;

	D->img = IMG_Load("1x/Musicon.png");
		if (D->img== NULL) {
			return ;
		}
	D->pos.x = 1750;
	D->pos.y = 30;
	
	E->img = IMG_Load("1x/Scoreunselected.png");
		if (D->img== NULL) {
			return ;
		}
	E->pos.x = 270;
	E->pos.y = 700;
	
	F->img = IMG_Load("1x/subrosa.png");
		if (D->img== NULL) {
			return ;
		}
	F->pos.x = 200;
	F->pos.y = 100;

}
void initBackground(image *Backg)
{
Backg->img= IMG_Load("1x/img.jpg");
	if (Backg->img == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return;
		}
	Backg->pos.x=0;
	Backg->pos.y=0;
	/*Backg->pos.w=(SCREEN_W); 
	Backg->pos.h=SCREEN_H;*/
}
void libererButtons(image A,image B, image C,image E,image F,image G)
{
	SDL_FreeSurface(A.img); 
	SDL_FreeSurface(B.img);
	SDL_FreeSurface(C.img);
	SDL_FreeSurface(E.img);
	SDL_FreeSurface(F.img);
	SDL_FreeSurface(G.img);
}
void afficher(image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,NULL,screen,&p.pos);
}
void afficherparposition(int position, image *A,image *B, image *C,image *D)
{
 switch (position)
 {
	case 1:
	A->img = IMG_Load("1x/Startselected.png");
	B->img=IMG_Load("1x/Settingsunselected.png");
	C->img=IMG_Load("1x/Scoreunselected.png");
	D->img = IMG_Load("1x/Quitunselected.png");
	break;
	case 2:
	A->img = IMG_Load("1x/Startunselected.png");
	B->img=IMG_Load("1x/Settingsselected.png");
	C->img=IMG_Load("1x/Scoreunselected.png");
	D->img = IMG_Load("1x/Quitunselected.png");
	break;
	case 3:
	A->img = IMG_Load("1x/Startunselected.png");
	B->img=IMG_Load("1x/Settingsunselected.png");
	C->img=IMG_Load("1x/Scoreselected.png");
	D->img = IMG_Load("1x/Quitunselected.png");
	break;
	case 4:
	A->img = IMG_Load("1x/Startunselected.png");
	B->img=IMG_Load("1x/Settingsunselected.png");
	C->img=IMG_Load("1x/Scoreunselected.png");
	D->img = IMG_Load("1x/Quitselected.png");
	break;

 }
}


void closeEverything()
{
	//atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(SDL_Quit);
}

