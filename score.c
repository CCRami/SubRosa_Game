#include "header.h"

void initscore(text *A,text *B,char meilleurnom[],int meilleurscore)
{
	char ch[20];
	A->position.x=400;
	A->position.y=540;
	A->textColor.r=127;
	A->textColor.g=0;
	A->textColor.b=255;
	A->font=TTF_OpenFont("ARIAL.ttf",70);
	strcpy (A->texte,meilleurnom);
	
	B->position.x=700;
	B->position.y=540;
	B->textColor.r=127;
	B->textColor.g=0;
	B->textColor.b=255;
	B->font=TTF_OpenFont("ARIAL.ttf",70);
	sprintf (ch,"%d",meilleurscore);
	strcpy (B->texte,ch);
	
	/*C->position.x=400;
	C->position.y=300;
	C->textColor.r=127;
	C->textColor.b=255;
	C->textColor.g=0;
	C->font=TTF_OpenFont("ARIAL.ttf",70);

	
	D->position.x=500;
	D->position.y=300;
	D->textColor.r=127;
	D->textColor.b=255;
	D->textColor.g=0;
	D->font=TTF_OpenFont("ARIAL.ttf",70);*/

}
void freescore(text A,text B)
{
	SDL_FreeSurface(A.surfaceTexte);
	SDL_FreeSurface(B.surfaceTexte);
	//SDL_FreeSurface(C.surfaceTexte);
	//SDL_FreeSurface(D.surfaceTexte);
	
}
void displayscore(text t,SDL_Surface *screen)
{
	t.surfaceTexte=TTF_RenderText_Solid(t.font,t.texte,t.textColor);
	SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}
int rollscore (SDL_Surface *screen,SDL_Event *event1,char meilleurnom[],int meilleurscore)
{
	image backg,menu;
	char ch[20];
        menu.img = IMG_Load("1x/Menureturnunselected.png");
	menu.pos.x = 100;
	menu .pos.y = 100;
	initBackground(&backg);
	backg.img=IMG_Load("fond.png");
	backg.pos.x=0;
	backg.pos.y=0;
        text A,B;
	SDL_Event event;
SDL_Color color = { 127, 0, 255 };
        TTF_Font * font4 = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 90);
	SDL_Surface * message4 = TTF_RenderText_Solid(font4,"Meilleur Score", color);
	SDL_Rect Message_rect4;
	Message_rect4.x = 500;  
	Message_rect4.y = 300;
	initscore (&A,&B,meilleurnom,meilleurscore);
int x=0,y=0;

 while (1)
{
 SDL_BlitSurface (backg.img,NULL,screen,&backg.pos);
 SDL_BlitSurface (menu.img,NULL,screen,&menu.pos);
SDL_BlitSurface(message4,NULL,screen,&Message_rect4);
 displayscore (A,screen);
 displayscore (B,screen);
 SDL_Flip(screen);
 while (SDL_PollEvent(&event))
{	switch (event.type)
	{
		case SDL_QUIT:
		{
			closeEverything();

			exit(0);
	        }
		break;
		case SDL_KEYDOWN:
	    if (event.key.keysym.sym == SDLK_ESCAPE)
		{
		event1->key.keysym.sym=SDLK_ESCAPE;
		//freescore(A,B);
		return 0;
		}
	        break;
		case SDL_MOUSEMOTION:
		SDL_GetMouseState(&x,&y);
		if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
					menu.img=IMG_Load("1x/Menureturnselected.png");
					
				}
		else 
					menu.img=IMG_Load("1x/Menureturnunselected.png");
		break;     		
		case SDL_MOUSEBUTTONDOWN:
       		SDL_GetMouseState(&x,&y);
		if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
					event1->key.keysym.sym=SDLK_ESCAPE;
					//freescore(A,B);
					return 0;
				}
				break;

//switch
}}}}





















