#include "header.h"

void initTextagent(text *A,text *B)
{
	A->position.x=650;
	A->position.y=90;
	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;
	A->font=TTF_OpenFont("ARIAL.ttf",70);

	
	B->position.x=600;
	B->position.y=320;
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
void afficherparpositionagent(int position, image *A,image *B, image *C,image *D,image *E,image *F,image *G, image *H,image *I,image *J)
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
	E->img = IMG_Load("1x/newgameselected.png");
	break;
	case 6:
	F->img = IMG_Load("1x/Menureturnselected.png");
	break;
	case 7:
	G->img = IMG_Load("1x/keyboard_selected.png");
	H->img = IMG_Load("1x/joystick_unselected.png");
	J->img=IMG_Load("1x/mouseunselected.png");
	break;
	case 8:
	G->img = IMG_Load("1x/keyboard_unselected.png");
	H->img = IMG_Load("1x/joystick_selected.png");
	J->img=IMG_Load("1x/mouseunselected.png");
	break;
	case 9:
	G->img = IMG_Load("1x/keyboard_unselected.png");
	H->img = IMG_Load("1x/joystick_unselected.png");
	J->img=IMG_Load("1x/mouseselected.png");
	break;
	case 10:
	I->img = IMG_Load("1x/continueselected.png");
	break;
 }
}
void initSettingsButtonsagent(image *A,image *B, image *C,image *D,image *E,image *F,image *G, image *H,image *I,image *J)
{
	A->img = IMG_Load("1x/p1selected.png");
		if (A->img== NULL) {
			return ;
		}
	A->pos.x = 680;
	A->pos.y = 180;
	
	B->img = IMG_Load("1x/p2.png");
		if (B->img== NULL) {
			return ;
		}
	B->pos.x = 1080;
	B->pos.y = 180;

	C->img = IMG_Load("1x/soloselected.png");
		if (C->img== NULL) {
			return ;
		}
	C->pos.x = 630;
	C->pos.y = 400;

	D->img = IMG_Load("1x/duounselected.png");
		if (D->img== NULL) {
			return ;
		}
	D->pos.x = 1030;
	D->pos.y = 400;
	
E->img = IMG_Load("1x/newgameunselected.png");
		if (D->img== NULL) {
			return ;
		}
	E->pos.x = 550;
	E->pos.y = 800;
F->img = IMG_Load("1x/Menureturnunselected.png");
		if (F->img== NULL) {
			return ;
		}
	F->pos.x = 100;
	F->pos.y = 100;
G->img = IMG_Load("1x/keyboard_selected.png");
		if (G->img== NULL) {
			return ;
		}
	G->pos.x = 830;
	G->pos.y = 600;
H->img = IMG_Load("1x/joystick_unselected.png");
		if (H->img== NULL) {
			return ;
		}
	H->pos.x = 1060;
	H->pos.y = 600;
I->img = IMG_Load("1x/continueunselected.png");
		if (I->img== NULL) {
			return ;
		}
	I->pos.x = 970;
	I->pos.y = 800;
J->img = IMG_Load("1x/mouseunselected.png");
		if (J->img== NULL) {
			return ;
		}
	J->pos.x = 600;
	J->pos.y = 600;
}
int paintOptionsScreenagent (SDL_Surface *screen,SDL_Event *event2,Mix_Chunk *chunk,int *gamemode,int *duo1, int *pic,int *input, int *choice)
{
SDL_Event event;
image men,women,solo,duo,start,backg,menu,clavier,manette,continuee,souris;
text perso,mode;
strcpy (perso.texte,"Choose your agent");
strcpy (mode.texte,"Choose a gamemode");
initBackground (&backg);
backg.img=IMG_Load ("1x/fond.png");
initTextagent (&perso,&mode);
initSettingsButtonsagent(&men,&women,&solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);
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
		afficher(clavier,screen);
		afficher(manette,screen);
		afficher(continuee,screen);
		afficher(souris,screen);
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
       	 		*pic=1;
       			Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
       	 }
if( ( x > women.pos.x ) && ( y > women.pos.y) && ( x < (women.pos.x+141) ) && ( y < (women.pos.y+141)))
       	 {		position=2;
       	 		*pic=2;
       			Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
       	 }
if( ( x > solo.pos.x ) && ( y > solo.pos.y) && ( x < (solo.pos.x+216) ) && ( y < (solo.pos.y+181)))
       	 {
       	 		position=3;
       	 		*duo1=0;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
				
       	 }
if( ( x > duo.pos.x ) && ( y > duo.pos.y) && ( x < (duo.pos.x+216) ) && ( y < (duo.pos.y+181)))
       	 {
       	 		position=4;
       	 		*duo1=1;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
				
       	 }
if( ( x > clavier.pos.x ) && ( y > clavier.pos.y) && ( x < (clavier.pos.x+216) ) && ( y < (clavier.pos.y+181)))
       	 {
       	 		position=7;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
       	 		*input=1;
				
       	 }

if( ( x > manette.pos.x ) && ( y > manette.pos.y) && ( x < (manette.pos.x+216) ) && ( y < (manette.pos.y+181)))
       	 {
       	 		position=8;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);
       	 		*input=3;	
				
       	 }
if( ( x > souris.pos.x ) && ( y > souris.pos.y) && ( x < (souris.pos.x+216) ) && ( y < (souris.pos.y+181)))
       	 {
       	 		position=9;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
       	 		*input=2;
				
       	 }
if( ( x > start.pos.x ) && ( y >start.pos.y) && ( x < (start.pos.x+380) ) && ( y < (start.pos.y+171)))
       	 {
       	 	Mix_PlayChannel(-1,chunk,0);
			*gamemode=2;
			return 0;
		}
if( ( x > continuee.pos.x ) && ( y >continuee.pos.y) && ( x < (continuee.pos.x+380) ) && ( y < (continuee.pos.y+171)))
       	 {
       	 	Mix_PlayChannel(-1,chunk,0);
       	 	*choice=2;
			*gamemode=2;
			return 0;
		}
if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{	Mix_PlayChannel(-1,chunk,0);
					*duo1=0;
					*pic=1;
					event2->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(perso.font);
					TTF_CloseFont(mode.font);
					return 0;
				}

		}
break ;
case SDL_MOUSEMOTION:
			SDL_GetMouseState(&x,&y);
if( ( x > start.pos.x ) && ( y >start.pos.y) && ( x < (start.pos.x+370) ) && ( y < (start.pos.y+177)))
       	 {
       	 		position=5;
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);		
       	 }
else if ( ( x > continuee.pos.x ) && ( y > continuee.pos.y) && ( x < (continuee.pos.x+370) ) && ( y < (continuee.pos.y+177)))
		{
       	 		position=10;
       	 		afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);		
       	 }
else if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
				position=6;
					afficherparpositionagent(position, &men,&women, &solo,&duo,&start,&menu,&clavier,&manette,&continuee,&souris);	
				}
else 
{menu.img=IMG_Load("1x/Menureturnunselected.png");
start.img = IMG_Load("1x/newgameunselected.png");
continuee.img = IMG_Load("1x/continueunselected.png");}
       	 		
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





