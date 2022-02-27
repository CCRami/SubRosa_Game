#include "header.h"

void initText(text *A,text *B,text *C,text *D)
{
	A->position.x=820;
	A->position.y=200;
	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;
	A->font=TTF_OpenFont("ARIAL.ttf",70);

	
	B->position.x=880;
	B->position.y=350;
	B->textColor.r=255;
	B->textColor.g=255;
	B->textColor.b=0;
	B->font=TTF_OpenFont("ARIAL.ttf",70);

	
	C->position.x=750;
	C->position.y=500;
	C->textColor.r=255;
	C->textColor.g=255;
	C->textColor.b=0;
	C->font=TTF_OpenFont("ARIAL.ttf",70);

	
	D->position.x=850;
	D->position.y=800;
	D->textColor.r=255;
	D->textColor.g=255;
	D->textColor.b=0;
	D->font=TTF_OpenFont("ARIAL.ttf",70);

}
void freeText(text A,text B,text C, text D)
{
	SDL_FreeSurface(A.surfaceTexte);
	SDL_FreeSurface(B.surfaceTexte);
	SDL_FreeSurface(C.surfaceTexte);
	SDL_FreeSurface(D.surfaceTexte);
	
}
void displayText(text t,SDL_Surface *screen)
{
	t.surfaceTexte=TTF_RenderText_Solid(t.font,t.texte,t.textColor);
	SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}
void afficherparpositionsettings(int position, image *A,image *B)
{
	switch (position)
 {
	case 1:
	A->img = IMG_Load("1x/ON.png");
	B->img=IMG_Load("1x/OFFunselected.png");
	break;
	case 2:
	A->img = IMG_Load("1x/ONunselected.png");
	B->img=IMG_Load("1x/OFF.png");
	break;

 }
}
void initSettingsButtons(image *A,image *B, image *C,image *D,image *E,Mix_Chunk *chunk)
{
	A->img = IMG_Load("1x/plus.png");
		if (A->img== NULL) {
			return ;
		}
	A->pos.x = 1080;
	A->pos.y = 330;
	
	B->img = IMG_Load("1x/moins.png");
		if (B->img== NULL) {
			return ;
		}
	B->pos.x = 680;
	B->pos.y = 313;
	if (Mix_VolumeChunk(chunk, -1)!=0)
		C->img = IMG_Load("1x/OFFunselected.png");
	else
		C->img = IMG_Load("1x/OFF.png");
	C->pos.x = 680;
	C->pos.y = 630;
	
	if (Mix_VolumeChunk(chunk, -1)!=0)
		D->img = IMG_Load("1x/ON.png");
	else
		D->img = IMG_Load("1x/ONunselected.png");
	D->pos.x = 1080;
	D->pos.y = 630;
	
	E->img = IMG_Load("1x/Menureturnunselected.png");
		if (D->img== NULL) {
			return ;
		}
	E->pos.x = 100;
	E->pos.y = 100;

}
int paintOptionsScreen(SDL_Surface* screen,SDL_Event *event1,Mix_Chunk *chunk,int *volume)
{ 
	SDL_Event event;
	image soundup,sounddown,soundon,soundoff,menu,backg;
	text volumetx, volumenum, onoff, back;
	bool isSoundOn = true;
	strcpy(volumetx.texte,"Volume");
	snprintf( volumenum.texte,4, "%d",*volume);
	strcpy(onoff.texte,"SFX Volume");
	initBackground(&backg);
	backg.img=IMG_Load("1x/image.png");
	initText(&volumetx,&volumenum,&onoff,&back);
	initSettingsButtons(&soundup,&sounddown, &soundoff,&soundon,&menu,chunk);
	if ((*volume < 100)&&(*volume!=0))
		volumenum.position.x=905;
	else if(*volume == 0)
		volumenum.position.x=930;
	int position;
	while (1)
	{
		afficher (backg,screen);
		afficher(soundup,screen);
		afficher (sounddown,screen);
		afficher (soundon,screen);
		afficher (soundoff,screen);
		afficher (menu,screen);
		displayText(volumetx,screen);
		displayText(volumenum,screen);
		displayText(onoff,screen);
		SDL_Flip(screen);
		 int x=0, y=0 ;
while (SDL_PollEvent(&event))
{	switch (event.type)
		{case SDL_QUIT:
		{
			closeEverything();
			exit(0);
		}
		break;
case SDL_MOUSEBUTTONDOWN:
       	

      		SDL_GetMouseState(&x,&y);
        	
       	 if( ( x > soundup.pos.x ) && ( y > soundup.pos.y) && ( x < (soundup.pos.x+130) ) && ( y < (soundup.pos.y+116)))
       	 {
			if (*volume < 100)
				{*volume += 10;
				volumenum.position.x=905;}
			if (*volume == 100)
				volumenum.position.x=880;
			sprintf(volumenum.texte, "%d", *volume);
			volumenum.surfaceTexte = TTF_RenderText_Blended(volumenum.font, volumenum.texte, volumenum.textColor);
       	 	Mix_VolumeMusic (*volume);
       	 	Mix_PlayChannel(-1,chunk,0);
       	 }
       	 if( ( x > sounddown.pos.x ) && ( y > (sounddown.pos.y+12)) && ( x < (sounddown.pos.x+130) ) && ( y < (sounddown.pos.y+128)))
       	 {
       	 		if (*volume > 0)
					{*volume -= 10;
					volumenum.position.x=905;
					}
				if(*volume == 0)
					volumenum.position.x=930;
				sprintf(volumenum.texte, "%d", *volume);
				volumenum.surfaceTexte = TTF_RenderText_Blended(volumenum.font, volumenum.texte, volumenum.textColor);
				Mix_VolumeMusic (*volume);
				Mix_PlayChannel(-1,chunk,0);
       	 }
		if( ( x > soundon.pos.x ) && ( y > soundon.pos.y) && ( x < (soundon.pos.x+130) ) && ( y < (soundon.pos.y+116))) 
			{position=1;
			afficherparpositionsettings(position, &soundon,&soundoff);
			Mix_PlayChannel(-1,chunk,0);
			Mix_VolumeChunk(chunk, 128);
			}
		if( ( x > soundoff.pos.x ) && ( y > soundoff.pos.y) && ( x < (soundoff.pos.x+130) ) && ( y < (soundoff.pos.y+116)))
			{position=2;
			afficherparpositionsettings(position, &soundon,&soundoff);
			Mix_VolumeChunk(chunk, 0);
			Mix_PlayChannel(-1,chunk,0);
			}
		else if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
					event1->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(volumetx.font);
					TTF_CloseFont(volumenum.font);
					TTF_CloseFont(onoff.font);
					Mix_PlayChannel(-1,chunk,0);
					return 0;
				}
				break;
       	 

case SDL_MOUSEMOTION:
SDL_GetMouseState(&x,&y);
if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
					menu.img=IMG_Load("1x/Menureturnselected.png");
				}
else menu.img=IMG_Load("1x/Menureturnunselected.png");
break;      
case SDL_KEYDOWN:
	if (event.key.keysym.sym == SDLK_ESCAPE)
			
					{
					event1->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(volumetx.font);
					TTF_CloseFont(volumenum.font);
					TTF_CloseFont(onoff.font);
					return 0;}
	break;		
			}}}}

		
