#include"text.h"

void initText(text *A)
{
	A->position.x=300;
	A->position.y=50;
// couleur jaune
	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;
	
	A->font=TTF_OpenFont("arial.ttf",70);
}
void freeText(text A)
{
	SDL_FreeSurface(A.surfaceTexte);
}
void displayText(text t,SDL_Surface *screen)
{
	t.surfaceTexte=TTF_RenderText_Solid(t.font,"Menu",t.textColor);
	SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}

