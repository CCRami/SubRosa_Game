#include "header.h"

void initTextagent(text *A,text *B)
{
	A->position.x=650;
	A->position.y=100;
	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;
	A->font=TTF_OpenFont("ARIAL.ttf",70);

	
	B->position.x=600;
	B->position.y=420;
	B->textColor.r=255;
	B->textColor.g=255;
	B->textColor.b=0;
	B->font=TTF_OpenFont("ARIAL.ttf",70);

}
void freeTextagent(text A,text B)
{
	SDL_FreeSurface(A.surfaceTexte);
	SDL_FreeSurface(B.surfaceTexte);
}
void displayTextagent(text t,SDL_Surface *screen)
{
	t.surfaceTexte=TTF_RenderText_Solid(t.font,t.texte,t.textColor);
	SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}
void afficherparpositionagent(int position, image *A,image *B, image *C,image *D,image *E,image *F)
{
 switch (position)
 {
	case 1:
	A->img = IMG_Load("1x/p1selected.png");
	B->img=IMG_Load("1x/p2.png");

	break;
	
	case 2:
	A->img = IMG_Load("1x/p1.png");
	B->img=IMG_Load("1x/p2selected.png");

	break;
	
	case 3:
	C->img = IMG_Load("1x/soloselected.png");
	D->img = IMG_Load("1x/duounselected.png");
	break;
	
	case 4:
	C->img = IMG_Load("1x/solounselected.png");
	D->img = IMG_Load("1x/duoselected.png");
	break;
	
	case 5:
	E->img = IMG_Load("1x/Startselected.png");
	break;
	case 6:
	F->img = IMG_Load("1x/Menureturnselected.png");
	break;
	
 }
}
void initSettingsButtonsagent(image *A,image *B, image *C,image *D,image *E,image *F)
{
	A->img = IMG_Load("1x/p1.png");
		if (A->img== NULL) {
			return ;
		}
	A->pos.x = 680;
	A->pos.y = 230;
	
	B->img = IMG_Load("1x/p2.png");
		if (B->img== NULL) {
			return ;
		}
	B->pos.x = 1080;
	B->pos.y = 230;

	C->img = IMG_Load("1x/solounselected.png");
		if (C->img== NULL) {
			return ;
		}
	C->pos.x = 630;
	C->pos.y = 530;

	D->img = IMG_Load("1x/duounselected.png");
		if (D->img== NULL) {
			return ;
		}
	D->pos.x = 1030;
	D->pos.y = 530;
	
E->img = IMG_Load("1x/Startunselected.png");
		if (D->img== NULL) {
			return ;
		}
	E->pos.x = 750;
	E->pos.y = 800;

	F->img = IMG_Load("1x/Menureturnunselected.png");
		if (D->img== NULL) {
			return ;
		}
	F->pos.x = 100;
	F->pos.y = 100;
}
int paintOptionsScreenagent (SDL_Surface *screen,SDL_Event *event2,Mix_Chunk *chunk)
{
SDL_Event event;
image men,women,solo,duo,start,backg,menu;
text perso,mode;
strcpy (perso.texte,"Choose your agent");
strcpy (mode.texte,"Choose a gamemode");
initBackground (&backg);
backg.img=IMG_Load ("1x/fond.png");
initTextagent (&perso,&mode);
initSettingsButtonsagent(&men,&women,&solo,&duo,&start,&menu);
int position=1;
while (1)
{
		afficher(backg,screen);
		afficher(men,screen);
		afficher(women,screen);
		afficher(solo,screen);
		afficher(duo,screen);
		afficher(start,screen);
		afficher(menu,screen);
		displayTextagent (perso,screen);
		displayTextagent (mode,screen);
		SDL_Flip (screen);
		int x=0, y=0;
while (SDL_PollEvent (&event))
{
	switch (event.type)
{
	case SDL_QUIT:
		{
			closeEverything();
			exit(0);
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		{
			
			SDL_GetMouseState(&x,&y);
if( ( x > men.pos.x ) && ( y > men.pos.y) && ( x < (men.pos.x+141) ) && ( y < (men.pos.y+141)))
       	 {		position=1;
       			Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu);	
       	 }
if( ( x > women.pos.x ) && ( y > women.pos.y) && ( x < (women.pos.x+141) ) && ( y < (women.pos.y+141)))
       	 {		position=2;
       			Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu);	
       	 }
if( ( x > solo.pos.x ) && ( y > solo.pos.y) && ( x < (solo.pos.x+216) ) && ( y < (solo.pos.y+181)))
       	 {
       	 		position=3;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu);	
				
       	 }
if( ( x > duo.pos.x ) && ( y > duo.pos.y) && ( x < (duo.pos.x+216) ) && ( y < (duo.pos.y+181)))
       	 {
       	 		position=4;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu);	
				
       	 }
if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{	Mix_PlayChannel(-1,chunk,0);
					event2->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(perso.font);
					TTF_CloseFont(mode.font);
					return 0;
				}

			
		}
break ;
case SDL_MOUSEMOTION:
			SDL_GetMouseState(&x,&y);
if( ( x > start.pos.x ) && ( y >start.pos.y) && ( x < (start.pos.x+461) ) && ( y < (start.pos.y+171)))
       	 {
       	 		position=5;
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu);		
       	 }
else if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
				position=6;
					afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu);	
				}
else 
{menu.img=IMG_Load("1x/Menureturnunselected.png");
start.img = IMG_Load("1x/Startunselected.png");}
       	 		
break;
case SDL_KEYDOWN:
	if (event.key.keysym.sym == SDLK_ESCAPE)
			
		{
					Mix_PlayChannel(-1,chunk,0);
					event2->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(perso.font);
					TTF_CloseFont(mode.font);
					return 0;
	}
break ;
}

}


}
return 0;
}





